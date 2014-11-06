#ifndef KECCAK_UTILS_XORINTO_IMPL_H
#define KECCAK_UTILS_XORINTO_IMPL_H
#include "keccak/config.h"

#include <stdint.h>
#include <stdlib.h>

#ifndef _MSC_VER
#define ALWAYS_INLINE __attribute__((always_inline))
#else
#define ALWAYS_INLINE __inline
#endif

/* requires \valid(dest+(0..oplen-1)) && \valid_read(in+(0..oplen-1));
    assigns dest[0..oplen-1];
  */
static ALWAYS_INLINE int _xorinto(uint8_t* const restrict dest,
                           const uint8_t* const restrict in,
                           const size_t oplen) {
  size_t i;
  switch (oplen) {
#ifndef __FRAMAC__
#include "keccak/utils/xorinto-unrolled.gen.h"
#endif
    //#endif
    default:
      //@ loop variant oplen - i;
      for (i = 0; i < oplen; i++) {
        //@ assert i < oplen;
        dest[i] = dest[i] ^ in[i];
      }
  }
  return 0;
}
#endif  // KECCAK_UTILS_XORINTO_IMPL_H
