/* Print answers to all the KATs.
 */
#include <assert.h>
#include <stdint.h>

#include "keccak.h"
#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test-kats-input.h"
#include "keccak/tests/test-kats.h"

#define TEST(BITS, BYTES)                        \
  int test_shake##BITS(void);                    \
  int test_shake##BITS(void) {                   \
    keccak_sponge sponge;                        \
    const uint8_t* inpos = in;                   \
    for (size_t len = 0; len < 256; len++) {     \
      uint8_t out[BYTES] = {0};                  \
      uint8_t outs[BYTES] = {0};                 \
                                                 \
      shake##BITS##_init(&sponge);               \
      shake##BITS##_update(&sponge, inpos, len); \
      shake##BITS##_digest(&sponge, out, BYTES); \
                                                 \
      shake##BITS(outs, BYTES, inpos, len);      \
      if (memcmp(out, outs, BYTES) != 0) {       \
        fprintf(stderr, "FAIL!!!!!");            \
      }                                          \
                                                 \
      printkatshake(inpos, len, out, BYTES);     \
      inpos += len;                              \
    }                                            \
    return 0;                                    \
  }

#define test(BITS) TEST(BITS, 512)

#define runtest(BITS)          \
  do {                         \
    err |= test_shake##BITS(); \
    assert(err == 0);          \
  } while (0)

test(128) test(256) int test_shake(void) {
  int err = 0;
  runtest(128);
  runtest(256);
  return err;
}
#undef TEST
#undef test
#undef runtest
