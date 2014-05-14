#ifndef KECCAKC_H
#define KECCAKC_H
#include "keccak/config.h"
#include <stdint.h>

/*@  assigns ((uint64_t*)state)[0..24];
  @*/
void keccakf(register void* const state);
/*@  assigns state[0..24];
  @*/
void _keccakf_aligned(uint64_t* state);
#endif
