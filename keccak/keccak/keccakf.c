#include "keccak/keccak/keccakf-1600.h"
#include "libutil/libutil.h"

#include <stdalign.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* Misalignment-safe wrapper for Keccak-f.
 *
 * TODO: memclear makes hard to optimize
 */
void keccakf(register void* const istate) {
  uint64_t state[25];
  //if (((uintptr_t)istate & alignof(uint64_t)) != 0) {
  memcpy(state, istate, 200);
  _keccakf_aligned((uint64_t*)state);
  memcpy(istate, state, 200);
  memclear(state, 200);
  /*} else {
    _keccakf_aligned((uint64_t*)istate);
  }*/
}
