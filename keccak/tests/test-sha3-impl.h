/* Print answers to all the KATs.
 */
#include <assert.h>
#include <stdint.h>

#include "keccak.h"
#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test-kats-input.h"
#include "keccak/tests/test-kats.h"

#define TEST(BITS, BYTES)                        \
  int test_sha3_##BITS(void);                    \
  int test_sha3_##BITS(void) {                   \
    keccak_sponge sponge;                        \
    const uint8_t* inpos = in;                   \
    for (size_t len = 0; len < 256; len++) {     \
      uint8_t out[BYTES] = {0};                  \
      uint8_t outs[BYTES] = {0};                 \
                                                 \
      sha3_##BITS##_init(&sponge);               \
      sha3_##BITS##_update(&sponge, inpos, len); \
      sha3_##BITS##_digest(&sponge, out, BYTES); \
                                                 \
      sha3_##BITS(outs, BYTES, inpos, len);      \
      if (memcmp(out, outs, BYTES) != 0) {       \
        fprintf(stderr, "FAIL!!!!!");            \
      }                                          \
                                                 \
      printkat(inpos, len, out, BYTES);          \
      inpos += len;                              \
    }                                            \
    return 0;                                    \
  }

#define test(BITS) TEST(BITS, (BITS / 8))

#define runtest(BITS)          \
  do {                         \
    err |= test_sha3_##BITS(); \
    assert(err == 0);          \
  } while (0)

test(224) test(256) test(384) test(512) int test_sha3(void) {
  int err = 0;
  runtest(224);
  runtest(256);
  runtest(384);
  runtest(512);
  return err;
}
#undef TEST
#undef test
#undef runtest
