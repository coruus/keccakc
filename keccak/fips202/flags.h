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
 * have purposely been chosen as pseudo-random values to discourage API
 * consumers from violating the public/private API boundary.)
 */

#include <stdint.h>

#ifndef UINT64_C
// TODO(dlg): SC?
#define UINT64_C(VAL) (v##ULL)
#endif

// Flags indicating sponge state
#define hash_absorbing UINT64_C(0x53efb6b64647b401)  // AES-256[k=pad('libkeccakc')](pad('hash_absorbing')) 
#define hash_squeezing UINT64_C(0x44a50aed67ba8c04)  // AES-256[k=pad('libkeccakc')](pad('hash_squeezing')) 

// FIPS-202 modes of operation
#define flag_sha3_224 UINT64_C(0x1fa20e3b59c5ad5b)  // AES-256[k=pad('libkeccakc')](pad('flag_sha3_224')) 
#define flag_sha3_256 UINT64_C(0x70391fcfef16b030)  // AES-256[k=pad('libkeccakc')](pad('flag_sha3_256')) 
#define flag_sha3_384 UINT64_C(0x161aeacd69eee08a)  // AES-256[k=pad('libkeccakc')](pad('flag_sha3_384')) 
#define flag_sha3_512 UINT64_C(0x2ee92ac1b638dceb)  // AES-256[k=pad('libkeccakc')](pad('flag_sha3_512')) 
#define flag_shake128 UINT64_C(0xdbdf709850f90ff4)  // AES-256[k=pad('libkeccakc')](pad('flag_shake128')) 
#define flag_shake256 UINT64_C(0xfefb3f8c336ba9a1)  // AES-256[k=pad('libkeccakc')](pad('flag_shake256')) 

// Extended modes of operation
#define flag_shake192 UINT64_C(0xac2cbf0b5d705bce)  // AES-256[k=pad('libkeccakc')](pad('flag_shake192')) 
#define flag_shake224 UINT64_C(0xbc9497ec67635a78)  // AES-256[k=pad('libkeccakc')](pad('flag_shake224')) 
#define flag_shake384 UINT64_C(0x0306cbe5f8424c0f)  // AES-256[k=pad('libkeccakc')](pad('flag_shake384')) 
#define flag_shake512 UINT64_C(0xe346f869e944b70b)  // AES-256[k=pad('libkeccakc')](pad('flag_shake512'))
#undef FLAG

#endif  // KECCAK_FIPS_202_FLAGS_H
