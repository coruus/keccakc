#include "keccak/tests/test-kats.h"
#include "keccak/tests/test-sha3-impl.h"
#include "keccak/tests/test-shake-impl.h"
#include <stdint.h>

int main(void) {
  int err = 0;
  err = test_sha3();
  err = test_shake();
  return err;
}
