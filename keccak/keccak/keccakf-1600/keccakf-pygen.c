#include "keccak/config.h"
#include "keccak/keccak/keccak-1600.h"

#include <stdint.h>

KINLINE void _keccakf_aligned(register uint64_t* const a) {
  register uint64_t t, t1, t2, bc0, bc1, bc2, bc3, bc4;
#include "keccak/keccak/keccakf-1600/keccakf-pygen.gen.c"
  return;
}
