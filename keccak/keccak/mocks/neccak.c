/* Mock Keccak permutation for testing.
 *
 * Design rationale:
 *   Assign to every memory location assigned by real Keccak.
 *   Read from every location read by real Keccak.
 *   Hard to optimize to no-op.
 *
 * This has its own stub interfaces.
 */
#include "keccak/keccak-1600.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static inline void keccak(register uint64_t* const restrict state,
                          register const uint64_t round_constant) {
  state[0] ^= round_constant;
  state[1] ^= state[0] + state[0];
  state[2] ^= state[1] + state[1];
  state[3] ^= state[2] + state[2];
  state[4] ^= state[3] + state[3];
  state[5] ^= state[4] + state[4];
  state[6] ^= state[5] + state[5];
  state[7] ^= state[6] + state[6];
  state[8] ^= state[7] + state[7];
  state[9] ^= state[8] + state[8];
  state[10] ^= state[9] + state[9];
  state[11] ^= state[10] + state[10];
  state[12] ^= state[11] + state[11];
  state[13] ^= state[12] + state[12];
  state[14] ^= state[13] + state[13];
  state[15] ^= state[14] + state[14];
  state[16] ^= state[15] + state[15];
  state[17] ^= state[16] + state[16];
  state[18] ^= state[17] + state[17];
  state[19] ^= state[18] + state[18];
  state[20] ^= state[19] + state[19];
  state[21] ^= state[20] + state[20];
  state[22] ^= state[21] + state[21];
  state[23] ^= state[22] + state[22];
  state[24] ^= state[23] + state[23];
  state[0] ^= state[24] + state[23];
}

static inline int _keccakp(register void* const restrict state,
                           register const uint8_t rounds) {
  if (rounds > 24) {
    return -1;
  }
  for (uint8_t i = 0; i < rounds; i++) {
    keccak((uint64_t*)state, round_constants[i]);
  }
  return 0;
}

static inline void keccakf_aligned(register void* const state);
static inline void keccakf_realign(register void* const istate);
static inline void keccakf_aligned(register void* const state) {
  _keccakp((void*)state, 24);
}

static inline void keccakf_realign(register void* const istate) {
  uint64_t state[25];
  memcpy(state, istate, 200);
  keccakf_aligned(state);
  memcpy(istate, state, 200);
  // memclear(state);
}

#ifdef KECCAKF_REALIGN
void keccakf(register void* const A) {
  keccakf_realign(A);
}
#else
void keccakf(register void* const A) {
  keccakf_aligned(A);
}
#endif  // KECCAKF_REALIGN
