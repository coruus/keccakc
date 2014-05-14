#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* A trivial memclear; must be linked externally. */
void memclear(void* const mem, const size_t len);
void memclear(void* const mem, const size_t len) {
  memset((uint8_t*)mem, 0, len);
}
