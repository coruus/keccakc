#ifndef KECCAK_CONSTRUCTIONS_SPONGE_HELPERS_IMPL_H
#define KECCAK_CONSTRUCTIONS_SPONGE_HELPERS_IMPL_H
#include "keccak/config.h"
#include "keccak/rte/rte.h"
#include "keccak/constructions/sponge.h"

#include <stdint.h>
#include <stdlib.h>

/*@ requires sponge != \null;
    requires \valid(sponge);
    behavior nulptr:
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
  if ((rate >= spongelen) || (rate == 0)) {
    /*@ assert !(0 < rate < spongelen); */
    return -1;
  }
  /*@ assert sponge != \null;  */
  /*@ assert (0 < rate < 200); */
  /*@ assert \valid(sponge);   */
  sponge->rate = rate;
  /*@ assert sponge->rate == rate;            */
  /*@ assert sponge->rate > 0;                */
  sponge->position = 0;
  /*@ assert sponge->position < sponge->rate; */
  /*@ assert sponge->position == 0;           */
  /*@ assert sponge_invariant(sponge);        */
  sponge->flags = 0;

#ifdef FRAMAC
  // This code is specialized for Keccak-f
  /*@ assert spongelen == 200;        */
  /*@ loop variant 24 - i;            */
  for (size_t i = 0; i < 25; i++) {
    /*@ assert \valid(sponge->a + i); */
    sponge->a[i] = 0;
  }
  // End specialized code.
#endif
  memset_s(sponge->a, spongelen, 0, spongelen);

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
  //@ assert sponge != \null;
  if ((sponge->rate > spongelen) || (sponge->rate < 1)) {
    // The sponge must have a rate >= 1 byte and <= spongelen bytes.
    // (The 199 byte limit is stronger than is required, but it seems
    // likely that < 4-bit security strength is an error.)
    /*@ assert !(0 < sponge->rate < spongelen);  */
    /*@ assert !sponge_invariant(sponge);        */
    goto err;
  }
  if (sponge->position >= sponge->rate) {
    // sponge->position == sponge->rate: the permutation should have
    // been applied, but wasn't.
    // sponge->position > sponge->rate: something is seriously wrong.
    /*@ assert !sponge_invariant(sponge);  */
    /*@ assert sponge->rate < spongelen;   */
    goto err;
  }
  // The sponge invariant is true.
  /*@ assert sponge->position < sponge->rate;  */
  /*@ assert sponge_invariant(sponge);         */
  /*@ assert ret == 0;                         */
  goto done;
  __builtin_unreachable();

err:
  // The sponge invariant is violated.
  /*@ assert !sponge_invariant(sponge);  */
  // SOFT_RTE(sponge_invariant);
  ret = -1;
done:
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
