/* Like the Keccak Team's compact implementation of Keccak, but even
 * smaller.
 *
 * Implemented by: David Leon Gil
 * License: CC0
 */
#include "keccak/config.h"
#include "keccak/keccak/keccak-1600.h"
#include "keccak/keccak/keccakp-1600.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t rotation_constants[24] = {1,
                                               3,
                                               6,
                                               10,
                                               15,
                                               21,
                                               28,
                                               36,
                                               45,
                                               55,
                                               2,
                                               14,
                                               27,
                                               41,
                                               56,
                                               8,
                                               25,
                                               43,
                                               62,
                                               18,
                                               39,
                                               61,
                                               20,
                                               44};
static const uint8_t pi_lanes[25] = {10,
                                     7,
                                     11,
                                     17,
                                     18,
                                     3,
                                     5,
                                     16,
                                     8,
                                     21,
                                     24,
                                     4,
                                     15,
                                     23,
                                     19,
                                     13,
                                     12,
                                     2,
                                     20,
                                     14,
                                     22,
                                     9,
                                     6,
                                     1};

// TODO(dlg): verify
#if 0
static inline uint8_t rc(register uint8_t n) {
  uint8_t acc = 1;
  for (register uint8_t i = 0; i < n; i++) {
     acc += i;
  }
  return acc;
}
#endif

static INLINE uint64_t rol(register const uint64_t x, register const uint8_t shift) {
  if ((shift % 64) == 0) {
    return x;
  } else {
    return (x << shift) | (x >> (64 - shift));
  }
}

static INLINE uint8_t mod5(register const uint8_t i) {
  return i % 5;
}

static INLINE void keccakr(register uint64_t* const restrict state,
                           register const uint64_t round_constant) {
  uint64_t BC[5] = {0};
  register uint64_t t = 0;
  register uint8_t x, y;

  // Theta
  for (x = 0; x < 5; x++) {
    BC[x] = 0;
    for (y = 0; y < 25; y += 5) {
      BC[x] ^= state[x + y];
    }
  }
  for (x = 0; x < 5; x++) {
    t = BC[mod5(x + 4)] ^ rol(BC[mod5(x + 1)], 1);
    for (y = 0; y < 25; y += 5) {
      state[y + x] ^= t;
    }
  }

  // Rho and pi
  t = state[1];
  for (x = 0; x < 24; x++) {
    BC[0] = state[pi_lanes[x]];
    state[pi_lanes[x]] = rol(t, rotation_constants[x]);
    t = BC[0];
  }

  // Chi
  for (y = 0; y < 25; y += 5) {
    for (x = 0; x < 5; x++) {
      BC[x] = state[y + x];
    }
    for (x = 0; x < 5; x++) {
      state[y + x] = BC[x] ^ ((~BC[mod5(x + 1)]) & BC[mod5(x + 2)]);
    }
  }

  // Iota
  state[0] ^= round_constant;
}

static inline int _keccakp(register void* const restrict state,
                           register const uint8_t rounds) {
  if (rounds > 24) {
    return -1;
  }
  for (uint8_t i = (24 - rounds); i < rounds; i++) {
    keccakr((uint64_t*)state, round_constants[i]);
  }
  return 0;
}

KINLINE void _keccakf_aligned(uint64_t* const state) {
  _keccakp((void*)state, 24);
}
