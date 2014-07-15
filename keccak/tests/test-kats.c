#include "keccak/tests/test-kats.h"
#include "keccak/tests/test-sha3-impl.h"
#include "keccak/tests/test-shake-impl.h"

#include <stdint.h>
#include <stdio.h>

#ifndef TEST_KATS_AS_FUNCTION
#define test_kats main
#endif

int test_kats(void) {
  int err = 0;
  err = test_sha3();
  err = test_shake();
  return err;
}
