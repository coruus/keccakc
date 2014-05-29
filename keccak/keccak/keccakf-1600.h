#ifndef KECCAK_KECCAK_KECCAKF_1600_H
#define KECCAK_KECCAK_KECCAKF_1600_H
#include "keccak/config.h"
#include <stdint.h>

/*@  assigns ((uint64_t*)state)[0..24];
  @*/
void keccakf(register void* const state);
/*@  assigns state[0..24];
  @*/
void _keccakf_aligned(uint64_t* state);

#ifdef __clang__
/*
   The type `uv` is a vector of four sixty-four bit integers; this
   is optimal for performance on 256-bit-width vector units. It may
   be somewhat worse on narrow vector units.

   The memory layout is natural; i.e., ((state + 1)[0]) - state[0] == 32.
*/
void keccakf_vec(register void* const state);
typedef uint64_t uv __attribute__((ext_vector_type(4)));
void _keccakf_aligned_vec(uv* state);
#endif

#endif  // KECCAK_KECCAK_KECCAKF_1600_H
