#ifndef KECCAK_CONSTRUCTIONS_SPONGE_IMPL_H
#define KECCAK_CONSTRUCTIONS_SPONGE_IMPL_H
#include "keccak/config.h"
#include "keccak/constructions/sponge-helpers-impl.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccak-1600.h"
#include "keccak/utils/xorinto-impl.h"
#include "keccak/utils/c11shim.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static INLINE size_t _sponge_absorb_once(register keccak_sponge* const restrict sponge,
                                         register const uint8_t* const restrict in,
                                         register const size_t inlen) {
  register size_t canabsorb = sponge->rate - sponge->absorbed;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->absorbed;

  if (canabsorb > inlen) {
    _xorinto(state, in, inlen);
    sponge->absorbed += inlen;
    //@ assert sponge->absorbed < sponge->rate;
    return inlen;
  } else {  // canabsorb <= inlen
    _xorinto(state, in, canabsorb);
    keccakf(sponge->a);
    sponge->absorbed = 0;
    return canabsorb;
  }
}

/*@ //requires valid_sponge(sponge);
  @ requires 0 <= sponge->rate < 200;
  @ requires sponge->squeezed < sponge->rate;
  @ ensures sponge->squeezed < sponge->rate;
  @ behavior squeeze_dry:
  @   assumes outlen >= cansqueeze(sponge);
  @   ensures sponge->squeezed == 0;
  @   ensures \result ==\old(cansqueeze(sponge));
  @   assigns sponge->a[0..24], sponge->squeezed;
  @   assigns out[0..\old(cansqueeze(sponge))-1];
  @ behavior still_wet:
  @   assumes outlen < cansqueeze(sponge);
  @   ensures sponge->squeezed == \old(sponge->squeezed) + outlen;
  @   ensures \result == outlen;
  @   assigns sponge->squeezed;
  @   assigns out[0..outlen-1];
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
static INLINE size_t _sponge_squeeze_once(register keccak_sponge* const restrict sponge,
                                          register uint8_t* const restrict out,
                                          register const size_t outlen) {
  //@ assert cansqueeze(sponge) > 0;
  register size_t cansqueeze = sponge->rate - sponge->squeezed;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->squeezed;
  //@ assert sponge->rate < 200;
  //@ assert sponge->squeezed < sponge->rate;
  //@ assert sponge->squeezed < 200;
  //@ assert \valid(state);

  register size_t squeezed;

  if (cansqueeze > outlen) {
    // We can squeeze more bytes out of the sponge than the output
    // can hold. So:
    //@assert outlen < cansqueeze(sponge);
    memcpy_s(out, outlen, state, 200, outlen);  // Copy out the bytes we need,
    sponge->squeezed += outlen;                 // advance the squeezed position,
    squeezed = outlen;                          // and return #bytes squeezed.
    //@ assert sponge->squeezed < sponge->rate;
    //@ assert cansqueeze(sponge) > 0;
    //@ assert squeezed >= 0;
  } else {
    // More output has been requested than we can sqeeze from the
    // sponge. So:
    memcpy_s(out, outlen, state, 200, cansqueeze);  // Squeeze the sponge dry,
    keccakf(sponge->a);                             // apply the permutation,
    sponge->squeezed = 0;                           // reset the sponge position,
    squeezed = cansqueeze;                          // and return #bytes squeezed.
  }
  //@ assert    (outlen >= squeezed > 0) || (outlen == squeezed == 0);
  return squeezed;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(out+(0..outlen-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->squeezed;
  @ ensures \result == 0;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE int _sponge_squeeze(register keccak_sponge* const restrict sponge,
                                  register uint8_t* const restrict out,
                                  register const size_t outlen) {
  //@ assert cansqueeze(sponge) > 0;
  //@ assert sponge_invariant(sponge);
  register size_t remaining = outlen;
  register size_t outpos = 0;
  //@ loop variant remaining - 1;
  while (remaining) {
    //@ assert remaining > 0;
    register size_t squeezed = _sponge_squeeze_once(sponge, &out[outpos], remaining);
    // Progress:
    //@ assert squeezed > 0;
    // No overflow:
    //@ assert (remaining - squeezed) > 0;
    remaining -= squeezed;
    outpos += squeezed;
    //@ assert remaining == (outlen - outpos);
  }
  //@ assert outpos == outlen;
  //@ assert remaining == 0;
  return (int)remaining;
}

/*@ //requires valid_sponge(sponge);
  @ requires 0 <= sponge->rate < 200;
  @ requires sponge->squeezed < sponge->rate;
  @ ensures sponge->squeezed < sponge->rate;
  @ behavior squeeze_dry:
  @   assumes outlen >= cansqueeze(sponge);
  @   ensures sponge->squeezed == 0;
  @   ensures \result ==\old(cansqueeze(sponge));
  @   assigns sponge->a[0..24], sponge->squeezed;
  @   assigns out[0..\old(cansqueeze(sponge))-1];
  @ behavior still_wet:
  @   assumes outlen < cansqueeze(sponge);
  @   ensures sponge->squeezed == \old(sponge->squeezed) + outlen;
  @   ensures \result == outlen;
  @   assigns sponge->squeezed;
  @   assigns out[0..outlen-1];
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
static INLINE size_t
_sponge_squeeze_xor_once(register keccak_sponge* const restrict sponge,
                         register uint8_t* const restrict out,
                         register const size_t outlen) {
  //@ assert cansqueeze(sponge) > 0;
  register size_t cansqueeze = sponge->rate - sponge->squeezed;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->squeezed;
  //@ assert sponge->rate < 200;
  //@ assert sponge->squeezed < sponge->rate;
  //@ assert sponge->squeezed < 200;
  //@ assert \valid(state);

  register size_t squeezed;

  if (cansqueeze > outlen) {
    // We can squeeze more bytes out of the sponge than the output
    // can hold. So:
    //@assert outlen < cansqueeze(sponge);
    _xorinto(out, state, 200);   // Copy out the bytes we need,
    sponge->squeezed += outlen;  // advance the squeezed position,
    squeezed = outlen;           // and return #bytes squeezed.
                                 //@ assert sponge->squeezed < sponge->rate;
                                 //@ assert cansqueeze(sponge) > 0;
                                 //@ assert squeezed >= 0;
  } else {
    // More output has been requested than we can sqeeze from the
    // sponge. So:
    _xorinto(out, state, 200);  // Squeeze the sponge dry,
    keccakf(sponge->a);         // apply the permutation,
    sponge->squeezed = 0;       // reset the sponge position,
    squeezed = cansqueeze;      // and return #bytes squeezed.
  }
  //@ assert    (outlen >= squeezed > 0) || (outlen == squeezed == 0);
  return squeezed;
}

/*@ requires valid_sponge(sponge);
  @ requires \valid(out+(0..outlen-1));
  @ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..24], sponge->squeezed;
  @ ensures \result == 0;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
 */
static INLINE int _sponge_squeeze_xor(register keccak_sponge* const restrict sponge,
                                      register uint8_t* const restrict out,
                                      register const size_t outlen) {
  //@ assert cansqueeze(sponge) > 0;
  //@ assert sponge_invariant(sponge);
  register size_t remaining = outlen;
  register size_t outpos = 0;
  //@ loop variant remaining - 1;
  while (remaining) {
    //@ assert remaining > 0;
    register size_t squeezed = _sponge_squeeze_xor_once(sponge, &out[outpos], remaining);
    // Progress:
    //@ assert squeezed > 0;
    // No overflow:
    //@ assert (remaining - squeezed) > 0;
    remaining -= squeezed;
    outpos += squeezed;
    //@ assert remaining == (outlen - outpos);
  }
  //@ assert outpos == outlen;
  //@ assert remaining == 0;
  return (int)remaining;
}

/*@ requires \valid(sponge);
  @ requires \valid(in+(0..inlen-1));
  @ requires sponge->absorbed < sponge->rate;
  @ ensures sponge->absorbed < sponge->rate;
  @ assigns sponge->a[0..24], sponge->squeezed;
  @ ensures \result == 0;
 */
static INLINE int _sponge_absorb(register keccak_sponge* const restrict sponge,
                                 register const uint8_t* const restrict in,
                                 register const size_t inlen) {
  register size_t remaining = inlen;
  register size_t inpos = 0;
  //@ loop variant remaining;
  while (remaining) {
    //@assert remaining > 0;
    register size_t absorbed = _sponge_absorb_once(sponge, &in[inpos], remaining);
    //@ assert absorbed > 0;  // progress
    //@ assert (remaining - absorbed) > 0; // no overflow
    remaining -= absorbed;
    inpos += absorbed;
    //@ assert remaining == (inlen - inpos);
  }
  // @assert inpos == inlen;
  // @assert remaining == 0;
  return (int)remaining;
}

#endif  // KECCAK_CONSTRUCTIONS_SPONGE_IMPL_H
