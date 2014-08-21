#ifndef KECCAK_CONSTRUCTIONS_SPONGE_OPS_IMPL_H
#define KECCAK_CONSTRUCTIONS_SPONGE_OPS_IMPL_H
#include "keccak/config.h"
#include "keccak/constructions/sponge-helpers-impl.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccak-1600.h"
#include "keccak/rte/check-impl.h"
#include "keccak/rte/rte.h"
#include "keccak/utils/c11shim.h"
#include "keccak/utils/xorinto-impl.h"


static inline size_t _sponge_absorb_once(register keccak_sponge* const restrict sponge,
                                         register const uint8_t* const restrict in,
                                         register const size_t len) {
  /*@ assert sponge->rate - sponge->position > 0; */
  register size_t cando = sponge->rate - sponge->position;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->position;
  /*@ assert \valid(state[0..cando-1]);           */
  register size_t dolen;

  if (cando > len) {
    dolen = len;
    _xorinto(state, in, dolen);
    sponge->position += dolen;
    /*@ assert sponge->position < sponge->rate; */
    /*@ assert cando == len;                  */
  } else {
    /*@ assert cando <= len;                  */
    dolen = cando;
    /*@ assert cando == sponge->rate - sponge->position; */
    _xorinto(state, in, dolen);
    keccakf(sponge->a);
    sponge->position = 0;
  }
  return dolen;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(in+(0..len-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->position;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE void _sponge_absorb(register keccak_sponge* const restrict sponge,
                                 register const uint8_t* const restrict in,
                                 register const size_t len) {
  /*@ assert cansqueeze(sponge) > 0;            */
  /*@ assert sponge_invariant(sponge);          */
  register size_t remaining = len;
  register size_t pos = 0;
  /*@ loop variant remaining - 1;               */
  while (remaining) {
    /*@ assert remaining > 0;                   */
    register size_t done = _sponge_absorb_once(sponge, &in[pos], remaining);
    // Progress: (trivial from definition)
    /*@ assert done > 0;                        */
    // No overflow:
    /*@ assert (remaining - done) > 0;          */
    remaining -= done;
    pos += done;
    /*@ assert remaining == (len - pos);  */
  }
  /*@ assert pos == len;                  */
  /*@ assert remaining == 0;                    */
}

static inline size_t _sponge_squeeze_once(register keccak_sponge* const restrict sponge,
                                         register uint8_t* const restrict out,
                                         register const size_t len) {
  /*@ assert sponge->rate - sponge->position > 0; */
  register size_t cando = sponge->rate - sponge->position;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->position;
  /*@ assert \valid(state[0..cando-1]);           */
  register size_t dolen;

  if (cando > len) {
    dolen = len;
    memcpy(out, state, dolen);
    sponge->position += dolen;
    /*@ assert sponge->position < sponge->rate; */
    /*@ assert cando == len;                  */
  } else {
    /*@ assert cando <= len;                  */
    dolen = cando;
    /*@ assert cando == sponge->rate - sponge->position; */
    memcpy(out, state, dolen);
    keccakf(sponge->a);
    sponge->position = 0;
  }
  return dolen;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(out+(0..len-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->position;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE void _sponge_squeeze(register keccak_sponge* const restrict sponge,
                                 register uint8_t* const restrict out,
                                 register const size_t len) {
  /*@ assert cansqueeze(sponge) > 0;            */
  /*@ assert sponge_invariant(sponge);          */
  register size_t remaining = len;
  register size_t pos = 0;
  /*@ loop variant remaining - 1;               */
  while (remaining) {
    /*@ assert remaining > 0;                   */
    register size_t done = _sponge_squeeze_once(sponge, &out[pos], remaining);
    // Progress: (trivial from definition)
    /*@ assert done > 0;                        */
    // No overflow:
    /*@ assert (remaining - done) > 0;          */
    remaining -= done;
    pos += done;
    /*@ assert remaining == (len - pos);  */
  }
  /*@ assert pos == len;                  */
  /*@ assert remaining == 0;                    */
}

static inline size_t _sponge_squexor_once(register keccak_sponge* const restrict sponge,
                                         register uint8_t* const restrict out,
                                         register const size_t len) {
  /*@ assert sponge->rate - sponge->position > 0; */
  register size_t cando = sponge->rate - sponge->position;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->position;
  /*@ assert \valid(state[0..cando-1]);           */
  register size_t dolen;

  if (cando > len) {
    dolen = len;
    _xorinto(out, state, dolen);
    sponge->position += dolen;
    /*@ assert sponge->position < sponge->rate; */
    /*@ assert cando == len;                  */
  } else {
    /*@ assert cando <= len;                  */
    dolen = cando;
    /*@ assert cando == sponge->rate - sponge->position; */
    _xorinto(out, state, dolen);
    keccakf(sponge->a);
    sponge->position = 0;
  }
  return dolen;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(out+(0..len-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->position;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE void _sponge_squexor(register keccak_sponge* const restrict sponge,
                                 register uint8_t* const restrict out,
                                 register const size_t len) {
  /*@ assert cansqueeze(sponge) > 0;            */
  /*@ assert sponge_invariant(sponge);          */
  register size_t remaining = len;
  register size_t pos = 0;
  /*@ loop variant remaining - 1;               */
  while (remaining) {
    /*@ assert remaining > 0;                   */
    register size_t done = _sponge_squexor_once(sponge, &out[pos], remaining);
    // Progress: (trivial from definition)
    /*@ assert done > 0;                        */
    // No overflow:
    /*@ assert (remaining - done) > 0;          */
    remaining -= done;
    pos += done;
    /*@ assert remaining == (len - pos);  */
  }
  /*@ assert pos == len;                  */
  /*@ assert remaining == 0;                    */
}

static inline size_t _sponge_absqueeze_once(register keccak_sponge* const restrict sponge,
                                         register uint8_t* const restrict io,
                                         register const size_t len) {
  /*@ assert sponge->rate - sponge->position > 0; */
  register size_t cando = sponge->rate - sponge->position;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->position;
  /*@ assert \valid(state[0..cando-1]);           */
  register size_t dolen;

  if (cando > len) {
    dolen = len;
    _xorinto(state, io, dolen); memcpy(io, state, dolen);
    sponge->position += dolen;
    /*@ assert sponge->position < sponge->rate; */
    /*@ assert cando == len;                  */
  } else {
    /*@ assert cando <= len;                  */
    dolen = cando;
    /*@ assert cando == sponge->rate - sponge->position; */
    _xorinto(state, io, dolen); memcpy(io, state, dolen);
    keccakf(sponge->a);
    sponge->position = 0;
  }
  return dolen;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(io+(0..len-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->position;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE void _sponge_absqueeze(register keccak_sponge* const restrict sponge,
                                 register uint8_t* const restrict io,
                                 register const size_t len) {
  /*@ assert cansqueeze(sponge) > 0;            */
  /*@ assert sponge_invariant(sponge);          */
  register size_t remaining = len;
  register size_t pos = 0;
  /*@ loop variant remaining - 1;               */
  while (remaining) {
    /*@ assert remaining > 0;                   */
    register size_t done = _sponge_absqueeze_once(sponge, &io[pos], remaining);
    // Progress: (trivial from definition)
    /*@ assert done > 0;                        */
    // No overflow:
    /*@ assert (remaining - done) > 0;          */
    remaining -= done;
    pos += done;
    /*@ assert remaining == (len - pos);  */
  }
  /*@ assert pos == len;                  */
  /*@ assert remaining == 0;                    */
}


#endif  // KECCAK_CONSTRUCTIONS_SPONGE_OPS_IMPL_H
