/* Fully unrolled Keccak-f[1600] permutation; operating on vectors.

   License: CC0 (http://creativecommons.org/publicdomain/zero/1.0/)
*/

// These includes MUST be identical to the includes in keccakf-opt64.c
// and MUST all be guarded. (Some broken libcs will not like the macro
// magic that follows.)
#include "keccak/config.h"
#include "keccak/keccak/keccak-1600.h"
#include <stdint.h>
#include <stdlib.h>

#define uint64_t uv
#define _keccakf_aligned _keccakf_aligned_vec
#include "keccak/keccak/keccakf-1600/keccakf-opt64.c"
#undef uint64_t
