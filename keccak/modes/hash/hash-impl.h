#ifndef KECCAK_MODES_HASH_IMPL_H
#define KECCAK_MODES_HASH_IMPL_H
#include "keccak/config.h"
#include "keccak/constructions/sponge-helpers-impl.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccak-1600.h"
#include "keccak/modes/hash/dsbits.h"
#include "keccak/rte/rte.h"

#include <stdint.h>
#include <stdlib.h>

static INLINE int _hash_init(register keccak_sponge* const restrict sponge,
                             register const size_t rate,
                             register const uint64_t flags) {
  int err = _sponge_init(sponge, rate);
  if (err != 0) {
    return err;
  }
  sponge->flags = flags;
  return 0;
}

static INLINE int _hash_update(register keccak_sponge* const restrict sponge,
                               register const uint8_t* const restrict in,
                               register const size_t inlen,
                               register const uint64_t flags) {
  if (sponge->flags != flags) {
    SOFT_RTE(hash_flags);
  }
  return keccak_sponge_absorb(sponge, in, inlen);
}

static INLINE int _hash_finalize(register keccak_sponge* const restrict sponge,
                                 register const uint8_t lastbyte,
                                 register const uint64_t oldflags,
                                 register const uint64_t newflags) {
  int err = _sponge_checkinv(sponge);
  if (err != 0) {
    return err;
  } else if (sponge->squeezed != 0) {
    SOFT_RTE(hash_finalized);
  } else if (sponge->flags != oldflags) {
    SOFT_RTE(hash_flags);
  }

  register uint8_t* state = (uint8_t*)sponge->a;

  // Xor in the MBR padding end-bit.

  // Safety/correctness condition:
  //@ assert(sponge->absorbed < (sponge->rate - 1));
  state[sponge->rate - 1] ^= pad_end;

  // Absorb the last byte (including the MBR padding start-bit)
  // (This may cause the permutation to be applied.)
  uint8_t byte = lastbyte;
  err = keccak_sponge_absorb(sponge, &byte, 1);
  //@ assert(err == 0);

  // printstate(state);
  // Apply the permutation.
  keccakf(sponge->a);
  // And take the sponge out of the absorbing state.
  sponge->absorbed = 0;
  sponge->flags = newflags;
  return 0;
}

static INLINE int _hash_squeeze(register keccak_sponge* const restrict sponge,
                                register uint8_t* const restrict out,
                                register size_t outlen,
                                register const uint64_t flags) {
  int err = _sponge_checkinv(sponge);
  if (err != 0) {
    return err;
  } else if (sponge->absorbed != 0) {
    SOFT_RTE(hash_not_finalized);
  } else if (sponge->flags != flags) {
    SOFT_RTE(hash_flags);
  }
  return keccak_sponge_squeeze(sponge, out, outlen);
}
#endif  // KECCAK_MODES_HASH_IMPL_H
