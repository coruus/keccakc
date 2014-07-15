#ifndef KECCAK_CONSTRUCTIONS_SPONGE_HELPERS_IMPL_H
#define KECCAK_CONSTRUCTIONS_SPONGE_HELPERS_IMPL_H
#include "keccak/config.h"
#include "keccak/rte/rte.h"
#include "keccak/constructions/sponge.h"

#include <stdint.h>
#include <stdlib.h>

/*@ behavior nulptr:
      assumes sponge == \null;
      ensures \result < 0;
      assigns \nothing;
    behavior rate_err:
      assumes (sponge != \null) && !(0 < rate < sponge_bytelen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes (sponge != \null) && (0 < rate < sponge_bytelen);
      requires \valid(sponge);
      requires \valid(sponge->a+(0..24));
      ensures \result == 0;
      ensures \valid(sponge) ==> sponge_invariant(sponge);
      assigns sponge->absorbed, sponge->squeezed, sponge->rate,
              sponge->flags, sponge->a[0..24];
    complete behaviors;
    disjoint behaviors;
*/
static INLINE int _sponge_init(register keccak_sponge* const restrict sponge,
                               register const size_t rate) {
  if (sponge == NULL) {
    return -2;
  }
  if ((rate >= sponge_bytelen) || (rate == 0)) {
    //@ assert !(0 < rate < 200);
    return -1;
  }
  //@assert sponge != \null;
  //@assert (0 < rate < 200);
  //@assert \valid(sponge);
  sponge->rate = rate;
  //@assert sponge->rate == rate;
  //@assert sponge->rate > 0;
  sponge->absorbed = 0;
  //@assert sponge->absorbed < sponge->rate;
  sponge->squeezed = 0;
  //@assert sponge->squeezed < sponge->rate;
  //@assert sponge->squeezed == 0;
  //@assert sponge->absorbed == 0;
  //@assert !((sponge->absorbed != 0) && (sponge->squeezed != 0));
  //@assert sponge_invariant(sponge);

  sponge->flags = 0;

  //@ loop variant 24 - i;
  for (size_t i = 0; i < 25; i++) {
    //@ assert \valid(sponge->a + i);
    sponge->a[i] = 0;
  }
  ////@ loop variant 7 - i;
  // for (size_t i = 0; i < 7; i++) {
  //  sponge->padding[i] = sponge_padding[i];
  //}
  memset_s(sponge->a, 200, 0, 25 * 8);

  return 0;
}

/*@ behavior nulptr:
      assumes sponge == \null;
      ensures \result < 0;
      assigns \nothing;
    behavior notnul:
      assumes sponge != \null;
      requires \valid(sponge);
      ensures sponge_invariant(sponge) <==> (\result == 0);
      assigns \nothing;
    complete behaviors;
    disjoint behaviors;
*/
static INLINE int _sponge_checkinv(register const keccak_sponge* const sponge) {
  register int ret = 0;
  if (sponge == NULL) {
    return -2;
    // HARD_RTE(ptrnull);
  }
  //@ assert sponge != \null;
  if ((sponge->absorbed != 0) && (sponge->squeezed != 0)) {
    // The sponge can be in an absorbing or squeezing state, not both.
    // (But it is in neither immediately after the permutation is applied.)
    //@ assert (sponge->absorbed != 0) && (sponge->squeezed) != 0;
    //@ assert !sponge_invariant(sponge);
    goto err;
  }
  if ((sponge->rate > 199) || (sponge->rate < 1)) {
    // The sponge must have a rate >= 1 byte and <= 199 bytes.
    // (The 199 byte limit is stronger than is required, but it seems
    // likely that < 4-bit security strength is an error.)
    //@ assert !(0 < sponge->rate < 200);
    //@ assert !sponge_invariant(sponge);
    goto err;
  }
  if (sponge->absorbed >= sponge->rate) {
    // sponge->absorbed == sponge->rate: the permutation should have
    // been applied, but wasn't.
    // sponge->absorbed > sponge->rate: something is seriously wrong.
    //@ assert !sponge_invariant(sponge);
    //@ assert sponge->rate < 200;
    goto err;
  }
  if (sponge->squeezed >= sponge->rate) {
    // As above.
    //@ assert sponge->absorbed < sponge->rate;
    goto err;
  }
  //@ assert sponge->squeezed < sponge->rate;
  //@ assert sponge_invariant(sponge);
  goto okay;
/*else if (memcmp(sponge->padding, sponge_padding, 7 * 8) != 0) {
  goto err;
}*/
// The sponge's invariants are fine.
err:
  // SOFT_RTE(sponge_invariant);
  //@ assert !sponge_invariant(sponge);
  ret = -1;
okay:
  return ret;
}

#define checkinv(SPONGE)                \
  do {                                  \
    err = _sponge_checkinv(SPONGE);     \
    if (err != 0) {                     \
      SOFT_RTE(sponge_invariant);       \
    }                                   \
  } while (0)

#endif  // KECCAK_CONSTRUCTIONS_SPONGE_HELPERS_IMPL_H
