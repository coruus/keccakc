/* From Frama-C libc.
 * License: LGPL
 */
#include "libutil/libc-framac.h"
#include <stdint.h>
#undef memset
void* memset(void* dest, int val, size_t len) {
  unsigned char* ptr = (unsigned char*)dest;
  while (len-- > 0) *ptr++ = val;
  return dest;
}
