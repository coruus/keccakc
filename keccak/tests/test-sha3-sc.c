/* Print answers to all the KATs.
 */
#include <assert.h>
#include <stdint.h>
#include "keccak/fips202/sha3.h"
#include "keccak/constructions/sponge.h"
#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test1_sha3_kat_input.h"

#define TEST(BITS, BYTES)                    \
  int test_sha3_##BITS(void);                \
  int test_sha3_##BITS(void) {               \
    const uint8_t* inpos = in;               \
    for (size_t len = 0; len < 256; len++) { \
      uint8_t out[BYTES] = {0};              \
                                             \
      sha3_##BITS(out, BYTES, inpos, len);   \
                                             \
      printkat(inpos, len, out, BYTES);      \
      inpos += len;                          \
    }                                        \
    return 0;                                \
  }

#define test(BITS) TEST(BITS, (BITS / 8))

#define runtest(BITS)          \
  do {                         \
    err |= test_sha3_##BITS(); \
    assert(err == 0);          \
  } while (0)

test(224) test(256) test(384) test(512) int main(void) {
  int err = 0;
  runtest(224);
  runtest(256);
  runtest(384);
  runtest(512);
  return err;
}
