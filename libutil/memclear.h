#ifndef LIBUTIL_MEMCLEAR_H
#define LIBUTIL_MEMCLEAR_H
#include <stdlib.h>

void memclear(void* const, const size_t);
void state_scribble(void* const, const size_t);
void state_clear(void* const);
#endif  // LIBUTIL_MEMCLEAR_H
