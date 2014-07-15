#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "keccak/constructions/sponge-impl.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccakf-1600.h"
#include "keccak/rte/rte.h"
#include "keccak/utils/c11shim.h"

int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate) {
  return _sponge_init(sponge, rate);
}

int keccak_sponge_checkinv(register const keccak_sponge* const sponge) {
  return _sponge_checkinv(sponge);
}

/* _sponge_{absorb,squeeze}: Absorb or squeeze the request amount of input
   or output. Does not check that the sponge is in the correct state first.

   (For applications which alternate absorption and squeezing, it's desirable
   to check the validity of `{in,out}` and `{in,out}len` first, so that the
   permutation is not applied on calls which will fail; we thus leave this
   to keccak_sponge_{absorb,squeeze}.)
*/
// TODO: refactor and split to sponge-impl.h
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t inlen) {
  int err = 0;
  if ((in == NULL) || (inlen > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  if (sponge->squeezed != 0) {
    keccakf(sponge->a);
    sponge->squeezed = 0;
    //@ assert(sponge->absorbed == 0);
  }
  err |= _sponge_absorb(sponge, in, inlen);
  return err;
}

int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                          register uint8_t* const restrict out,
                          register const size_t outlen) {
  int err = 0;
  if ((out == NULL) || (outlen > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  if (sponge->absorbed != 0) {
    keccakf(sponge->a);
    sponge->absorbed = 0;
    //@ assert(sponge->squeezed == 0);
  }
  err |= _sponge_squeeze(sponge, out, outlen);
  return err;
}
