#ifndef KECCAK_TESTS_HELPERS_IMPL_H
#define KECCAK_TESTS_HELPERS_IMPL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef _MSC_VER
#define INLINE inline
#define SIZE_T_FORMAT "%zu"
#else
#define INLINE __inline
#define SIZE_T_FORMAT "%Iu"
#endif

static INLINE int checktest(const char* const restrict description,
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

static INLINE void _printkat(const uint8_t* const restrict msg,
                             const size_t msgbytelen,
                             const uint8_t* const restrict md,
                             const size_t mdlen,
                             const char* mdname) {
  size_t i;
  printf("Len = "SIZE_T_FORMAT"\n", msgbytelen * 8);
  printf("Msg = ");
  if (msgbytelen != 0) {
    for (i = 0; i < msgbytelen; i++) {
      printf("%02X", msg[i]);
    }
  } else {
    // assert(msg == NULL);
    printf("00");
  }
  printf("\n");
  printf("%s = ", mdname);
  for (i = 0; i < mdlen; i++) {
    printf("%02X", md[i]);
  }
  printf("\n");
}

#define printkat(msg, msgbytelen, md, mdlen) _printkat((msg), (msgbytelen), (md), (mdlen), "MD")
#define printkatshake(msg, msgbytelen, md, mdlen) _printkat((msg), (msgbytelen), (md), (mdlen), "Squeezed")

#endif
