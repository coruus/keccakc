/* The one sponge function that doesn't fit the folded-permutation
 * pattern: Applying multi-bitrate (MBR/10..1) padding.
 */
#ifndef KECCAK_CONSTRUCTIONS_SPONGE_PAD_H
#define KECCAK_CONSTRUCTIONS_SPONGE_PAD_H
#include "keccak/config.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccak-1600.h"
#include "keccak/utils/xorinto-impl.h"
#include "keccak/utils/c11shim.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/** Xor in MBR padding and domain-separator byte, then apply Keccak-f.
 *
 * @param sponge[in,out]
 * @param dsbyte[in]      The domain separator byte.
 */
/*@ requires sponge_invariant(sponge);
  @ assigns sponge->a[0..199];
  @ ensures sponge->position == 0;
  @ ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
  @*/
static INLINE void _sponge_pad(register keccak_sponge* const restrict sponge,
                               register const uint8_t dsbyte) {
  /*@ assert sponge->position < sponge->rate < 200; */
  sponge->a[sponge->position] ^= dsbyte;
  /*@ assert sponge->rate - 1 > 0;                  */
  sponge->a[sponge->rate - 1] ^= 0x80;
  keccakf(sponge->a);
  sponge->position = 0;
}

#endif  // KECCAK_CONSTRUCTIONS_SPONGE_PAD_H
