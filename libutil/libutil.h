#ifndef UTILS_LIBUTIL_H
#define UTILS_LIBUTIL_H
#include <stdlib.h>
extern void memclear(void* const, const size_t);
extern void state_scribble(void* const);
extern void state_clear(void* const);
extern uint64_t cpucycles(void);
#endif
