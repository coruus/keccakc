#include "keccak/keccak/keccakf-1600.h"
#include "libutil/libutil.h"

#include <stdalign.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int keccakp(register void* const restrict A, register const uint8_t rounds) {
  return _keccakp((uint64_t*)A, rounds);
}

void _keccakf_aligned(uint64_t* const A) {
  _keccakp(A, 24);
}

/* Misalignment-safe wrapper for Keccak-f.
 *
 * TODO(dlg): More efficient version for common case; memclear
 * means that it can't be fully optimized away.

void keccakf(register void* const istate) {
  uint64_t state[25];
  memcpy(state, istate, 200);
  _keccakf_aligned((uint64_t*)state);
  memcpy(istate, state, 200);
  memclear(state, 200);
}*/
