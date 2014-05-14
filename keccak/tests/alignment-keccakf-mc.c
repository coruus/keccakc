/* This code is intended to test whether an implementation of Keccak-f
 * produces correct results on misaligned input.
 *
 * TODO(dlg): Convert for library BIST.
 *
 * UBSanClean(keccakf) ==> OKAY
 *
 * This test allocates three pages of memory; the first and third page
 * are filled with distinct canaries. The second page is in the zero state.
 * The permutation is tested at each (valid) offset into the second page,
 * in sequence.
 *
 * In order to increase the probability of detecting an over-write error,
 * bytes i-1 and i+200 are saved and checked at each step.
 *
 * Finally, the same sequence of applications of Keccak-f is performed
 * over the middle page of a three-page region initialized with zero.
 * These results are compared to the canarized results.
 *
 * Because it allocates a spare page on either side of the test region,
 * this code will not generate a memory-protection fault even if the
 * permutation is incorrrect.[^isa_note]
 *
 * [^isa_note]: On Intel ISAs, this isn't true if the permutation uses
 * aligned loads or stores. (See the Intel reference for details.) The
 * permutation's machine-code must be verified (and possibly translated
 * if a memory protection fault must not be triggered.
 */
#include "keccak/utils/print-impl.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 4096

// Keccak-f MUST be externally linked; undefined behavior due to misalignment
// can cause these tests to be elided.
extern void keccakf(void* state);

static const uint64_t lower_canary = 0xac8276c9390d311c;
static const uint64_t upper_canary = 0x45d12a6e2568fcb3;

static inline void canary_fill(void* const buffer, const uint64_t canary) {
  uint64_t* buf64 = (uint64_t*)buffer;
  for (size_t i = 0; i < (PAGE_SIZE / 8); i++) {
    buf64[i] = canary;
  }
}

static inline int canary_check(void* const buffer, const uint64_t canary) {
  uint64_t* buf64 = (uint64_t*)buffer;
  for (size_t i = 0; i < (PAGE_SIZE / 8); i++) {
    if (buf64[i] != canary) {
      return -1;
    }
  }
  return 0;
}

int main(void) {
  uint8_t* buffer = (uint8_t*)valloc(PAGE_SIZE * 3);
  assert(buffer != NULL);

  memset(buffer, 0, PAGE_SIZE * 3);
  canary_fill(buffer, lower_canary);
  canary_fill(buffer + PAGE_SIZE * 2, upper_canary);

  for (size_t i = PAGE_SIZE; i < (PAGE_SIZE * 2 - 200); i++) {
    uint8_t iminus1 = buffer[i - 1];
    uint8_t iplus200 = buffer[i + 200];
    keccakf(buffer + i);
    if (iminus1 != buffer[i - 1]) {
      printf("failed iminus1 %zu\n", i);
      assert(0 && "failed iminus1");
    } else if (iplus200 != buffer[i + 200]) {
      printf("failed iplus200 %zu\n", i);
      assert(0 && "failed iplus200");
    }
  }

  int err = 0;
  err |= canary_check(buffer, lower_canary);
  err |= canary_check(buffer + PAGE_SIZE * 2, upper_canary);
  if (err != 0) {
    abort();
  }

  // Compute the same thing, but with zero-padding.
  uint8_t* bufzero = (uint8_t*)valloc(PAGE_SIZE * 3);
  assert(bufzero != NULL);
  memset(bufzero, 0, PAGE_SIZE * 3);
  for (size_t i = PAGE_SIZE; i < (PAGE_SIZE * 2 - 200); i++) {
    keccakf(bufzero + i);
  }

  err = memcmp(buffer + PAGE_SIZE, bufzero + PAGE_SIZE, PAGE_SIZE);
  if (err != 0) {
    printf("FAIL\n");
  } else {
    printf("OKAY\n");
  }
  free(buffer);
  free(bufzero);
  return err;
}
