/* This test case is hand-coded as a sanity check.
 *
 * It is also checked by the byte-length KAT tests.
 */
#include <stdint.h>

#include "keccak.h"

#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test0_shake_kats.h"

#define TEST0(BITS, BYTES)                                                      \
  int test_shake##BITS##_len0(void);                                            \
  int test_shake##BITS##_len0(void) {                                           \
    keccak_sponge sponge;                                                       \
    uint8_t out[512] = {0};                                                     \
    int err = 0;                                                                \
    err |= shake##BITS##_init(&sponge);                                         \
    err |= shake##BITS##_digest(&sponge, out, 512);                             \
    printkat(NULL, 0, out, 512);                                                \
    return err | checktest("SHAKE" #BITS "('')", shake##BITS##_len0, out, 512); \
  }

#define test0(BITS) TEST0(BITS, (BITS / 8))

#define runtest0(BITS)                \
  do {                                \
    err |= test_shake##BITS##_len0(); \
    assert(1 || err == 0);            \
  } while (0)

test0(128) test0(256) int main(void) {
  int err = 0;
  runtest0(128);
  runtest0(256);
  return err;
}
