#ifndef KECCAK_UTILS_XORINTO_IMPL_H
#define KECCAK_UTILS_XORINTO_IMPL_H
#include "keccak/config.h"

#include <stdint.h>
#include <stdlib.h>

/* requires \valid(dest+(0..oplen-1)) && \valid_read(in+(0..oplen-1));
    assigns dest[0..oplen-1];
  */
static INLINE int _xorinto(uint8_t* const restrict dest,
                           const uint8_t* const restrict in,
                           const size_t oplen) {
  switch (oplen) {
#include "keccak/utils/xorinto-unrolled.gen.h"
    default:
      //@ loop variant oplen - i;
      // pragma unroll 200;
      for (size_t i = 0; i < oplen; i++) {
        //@ assert i < oplen;
        dest[i] = dest[i] ^ in[i];
      }
  }
  return 0;
}
#endif  // KECCAK_UTILS_XORINTO_IMPL_H
