#ifndef KECCAK_KECCAK_KECCAKP_1600_KECCAKP_INTERFACE_IMPL_H
#define KECCAK_KECCAK_KECCAKP_1600_KECCAKP_INTERFACE_IMPL_H
#include <stdint.h>

int keccakp(register void* const restrict A, register const uint8_t rounds) {
  return _keccakp((uint64_t*)A, rounds);
}

void _keccakf_aligned(uint64_t* const A) {
  _keccakp(A, 24);
}
#endif
