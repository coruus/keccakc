/* License: 3BSD or LGPL.
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libutil/libutil.h"

/*@ behavior zero_len:
      assumes len == 0;
      assigns \nothing;
    behavior pos_len:
      assumes len > 0;
      requires mem != \null && \valid(mem+(0..len-1));
      assigns mem[0..len-1];
      ensures mem[0..len-1] == 0;
*/
void memclear(void* const mem, const size_t len) {
  memset((uint8_t*)mem, 0, len);
}

void state_scribble(void* const mem) {
  uint8_t* buf = (uint8_t*)mem;
#include "libutil/memclear.scribble.gen"
}

void state_clear(void* const mem) {
  uint8_t* buf = (uint8_t*)mem;
#include "libutil/memclear.zero.gen"
}
