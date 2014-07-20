#ifndef KECCAK_H
#define KECCAK_H
/* The public API to the draft FIPS-202 functions, and to a generic
 * Sponge[Keccak-f, pad] API.
 */

#include <stdlib.h>
#include <stdint.h>

#ifndef _MSC_VER
#include <stdalign.h>
#include <stdbool.h>
#else
#define restrict __restrict
#if defined(keccak_EXPORTS)
#define KECCAK_EXPORT __declspec(dllexport)
#else
#define KECCAK_EXPORT __declspec(dllexport)
#endif
#endif

#ifndef KECCAK_EXPORT
#define KECCAK_EXPORT
#endif

/* An opaque definition of the sponge structure.
 *
 * The details are purely in the private API; API consumers must
 * not tamper with them.
 */
#ifndef KECCAK_PRIVATE_API
typedef struct keccak_sponge { uint64_t _OPAQUE[32]; } keccak_sponge;
#else
#include "keccak/constructions/sponge.h"
#endif // KECCAK_PRIVATE_API
/********************************************************************
 * Simple interface to FIPS-202-defined functions.
 */
KECCAK_EXPORT 
int sha3_224(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
KECCAK_EXPORT int sha3_256(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
KECCAK_EXPORT int sha3_384(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
KECCAK_EXPORT int sha3_512(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);

KECCAK_EXPORT int shake128(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
KECCAK_EXPORT int shake256(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);

/********************************************************************
 * Init, update, digest interface to the FIPS-202-defined functions.
 *
 * Finalization is automatic and irreversible when digest is called.
 */

/* SHA-3 FOFs (fixed-output-length functions)
 *
 * The sponge state is immediately zeroed once the output is ready.
 * (The upper bytes are zeroed prior to attempting to copy the
 * output.)
 */
// SHA3-224
int sha3_224_init(register keccak_sponge* const restrict sponge);
int sha3_224_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_224_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);

// SHA3-256
int sha3_256_init(register keccak_sponge* const restrict sponge);
int sha3_256_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_256_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);

// SHA3-384
int sha3_384_init(register keccak_sponge* const restrict sponge);
int sha3_384_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_384_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);

// SHA3-512
int sha3_512_init(register keccak_sponge* const restrict sponge);
int sha3_512_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_512_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);



/* SHAKE VOFs (variable-output-length functions)
 *
 * Security strength equivalence against collisions, for an
 * output length of 32 bytes for SHAKE256:
 *    SHA3-512 ~ SHAKE256
 *
 * With respect to security against collision, for an output
 * length of >= 32 bytes:
 *    SHA2-256 ~ SHAKE128
 *
 * With respect to security against preimages, for an output
 * length of >= 32 bytes:
 *    SHA2-256 ~ SHAKE256
 *
 * Yes. This is somewhat confusing. Most applications of
 * variable-output-length functions need preimage-resistance;
 * they probably should use SHAKE256.
 */

// SHAKE128
int shake128_init(register keccak_sponge* const restrict sponge);
int shake128_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int shake128_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);

// SHAKE256
int shake256_init(register keccak_sponge* const restrict sponge);
int shake256_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int shake256_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);

/* Interface to the Sponge[Keccak-f, pad] construction.
 *
 * keccak_sponge instances must be initialized with keccak_sponge_init
 *
 * Then call keccak_sponge_absorb to absorb input; call keccak_sponge_squeeze
 * to produce output.
 *
 * A dry sponge is one for which sponge.absorbed == sponge.squeezed == 0
 *
 * These functions apply the Keccak permutation whenever the sponge is
 * dry, AND whenever the sponge is wet and the sponge switches from squeezing
 * to absorbing. (But not when the sponge is dry and the sponge switches
 * from squeezing to absorbing; i.e., the permutation is never applied two
 * times in a row without either absorbing input or squeezing output.)
 */
int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate);
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t inlen);
int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                          register uint8_t* const restrict out,
                          register const size_t outlen);
/* TODO(dlg):
int keccak_sponge_absorb_xor(register keccak_sponge* const restrict sponge,
                             register const uint8_t* const restrict in,
                             register const size_t inlen);
int keccak_sponge_squeeze_xor(register keccak_sponge* const restrict sponge,
                              register uint8_t* const restrict out,
                              register const size_t outlen);
*/
#endif  // KECCAK_H
