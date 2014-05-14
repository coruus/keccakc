/* The bits of the standard library we need. */
#include <stdint.h>
#include <stdlib.h>

void* memset(void* dest, int val, size_t len) {
  uint8_t* bytes = dest;
  for (size_t i = 0; i < len; i++) {
    bytes[i] = (uint8_t)val;
  }
  return NULL;
}

void* memcpy(void* dest, const void* src, size_t len) {
  for (size_t i = 0; i < len; i++) {
    ((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
  }
  return NULL;
}

int memcmp(const void* in1, const void* in2, size_t len) {
  for (size_t i = 0; i < len; i++) {
    uint8_t c1 = ((uint8_t*)in1)[i];
    uint8_t c2 = ((uint8_t*)in2)[i];
    if (c1 != c2) {
      return -1;
    }
  }
  return 0;
}
#if 0
//#define RTCHANDLER() do { abort(); } while(0)
#define RTCHANDLER() \
  do {               \
    return -1;       \
  } while (0)

#define require_rsize(LEN) \
  do {                     \
    if (LEN > RSIZE_MAX) { \
      RTCHANDLER();        \
    }                      \
  } while (0)

#define min2(i1, i2) ((i1 < i2) ? i1 : i2)
#define min3(i1, i2, i3) min2(min2(i1, i2), i3)

errno_t memset_s(void* dest, rsize_t destlen, int val, rsize_t oplen) {
  require_rsize(destlen);
  require_rsize(oplen);
  oplen = min2(destlen, oplen);
  for (rsize_t i = 0; i < oplen; i++) {
    (uint8_t*)dest = val;
  }
  return 0;
}

errno_t memcpy_s(void* dest, rsize_t destlen, void* src, rsize_t srclen, rsize_t oplen) {
  require_rsize(destlen);
  require_rsize(srclen);
  require_rsize(oplen);
  oplen = min3(destlen, srclen, oplen);
  for (rsize_t i = 0; i < oplen; i++) {
    ((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
  }
  return 0;
}
#endif
