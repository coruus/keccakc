#ifndef KECCAK_TESTS_HELPERS_IMPL_H
#define KECCAK_TESTS_HELPERS_IMPL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static inline int checktest(const char* const restrict description,
                            const uint8_t* const restrict known_answer,
                            const uint8_t* const restrict result,
                            const size_t bytelen) {
  // assert(known_answer != NULL);
  // assert(result != NULL);
  // assert(description != NULL);
  // assert(bytelen < RSIZE_MAX);
  printf("%s: ", description);
  if (memcmp(known_answer, result, bytelen) == 0) {
    printf("OKAY\n");
    return 0;
  } else {
    printf("FAIL\n");
    return -1;
  }
}

static inline void printkat(const uint8_t* const restrict msg,
                            const size_t msgbytelen,
                            const uint8_t* const restrict md,
                            const size_t mdlen) {
  printf("Len = %zu\n", msgbytelen * 8);
  printf("Msg = ");
  if (msgbytelen != 0) {
    for (size_t i = 0; i < msgbytelen; i++) {
      printf("%02X", msg[i]);
    }
  } else {
    // assert(msg == NULL);
    printf("00");
  }
  printf("\n");
  printf("MD = ");
  for (size_t i = 0; i < mdlen; i++) {
    printf("%02X", md[i]);
  }
  printf("\n");
}

#endif
