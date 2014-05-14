#ifndef KECCAK_FIPS202_FLAGS_H
#define KECCAK_FIPS202_FLAGS_H
/* The same sponge structure is used for all of the hash modes.
 *
 * In order to ensure that the no-absorbing-after-finalization
 * constraint is observed, two flag values are defined for
 * sponge states.
 *
 * These flag values are XORed with mode-of-operation flags.
 *
 * (In some applications, it may be desirable to chooose random
 * values at initialization to mask sponge structures in memory.)
 *
 * (No facilities for this are as yet been provided, but the constants
 * have purposely been chosen as random values to discourage API consumers
 * from violating the public/private API boundary.)
 */

#include <stdint.h>

#ifndef UINT64_C
// TODO(dlg): SC?
#define UINT64_C(VAL) (v##ULL)
#endif

#define FLAG(NAME, VAL) static const uint64_t NAME = UINT64_C(VAL)

// Flags to indicate sponge state.
FLAG(hash_absorbing, 0x37f0ec3b0aadfa9d);
FLAG(hash_squeezing, 0x8a6fe7c7dc8e8693);

// NIST-defined modes of operation.
FLAG(flag_sha3_224, 0x554b0edefdab2bdc);
FLAG(flag_sha3_256, 0xa1368f2074321d98);
FLAG(flag_sha3_384, 0x66bd6e1188927c1b);
FLAG(flag_sha3_512, 0xc5ed05c8db10db4e);

FLAG(flag_shake128, 0xf4266a546a491160);
FLAG(flag_shake256, 0x129ad6509bc9bb8f);
#endif  // KECCAK_FIPS_202_FLAGS_H
