/* This test case is hand-coded as a sanity check.
 *
 * It is also checked by the byte-length KAT tests.
 */
#include <stdint.h>

#include "keccak.h"

#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test0_sha3_kats.h"

#define TEST0(BITS, BYTES)                                                        \
  int test_sha3_##BITS##_len0(void);                                              \
  int test_sha3_##BITS##_len0(void) {                                             \
    keccak_sponge sponge;                                                         \
    uint8_t out[BYTES] = {0};                                                     \
    int err = 0;                                                                  \
    err |= sha3_##BITS##_init(&sponge);                                           \
    err |= sha3_##BITS##_digest(&sponge, out, BYTES);                             \
    printkat(NULL, 0, out, BYTES);                                                \
    return err | checktest("SHA3-" #BITS "('')", sha3_##BITS##_len0, out, BYTES); \
  }

#define test0(BITS) TEST0(BITS, (BITS / 8))

#define runtest0(BITS)                \
  do {                                \
    err |= test_sha3_##BITS##_len0(); \
    assert(err == 0);                 \
  } while (0)

test0(224) test0(256) test0(384) test0(512) int main(void) {
  int err = 0;
  runtest0(224);
  runtest0(256);
  runtest0(384);
  runtest0(512);
  return err;
}
