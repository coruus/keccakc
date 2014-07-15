#ifndef UTILS_LIBUTIL_H
#define UTILS_LIBUTIL_H
#include <stdlib.h>
#ifndef NO_LIBUTIL
extern void memclear(void* const, const size_t);
extern void state_scribble(void* const);
extern void state_clear(void* const);
extern uint64_t cpucycles(void);
#else
#include <string.h>
#define memclear(DST, LEN) memset_s((DST), (LEN), 0, (LEN))
#define state_scribble(A) memset_s((A), 200, 0xc1, 200)
#define state_clear(A) memset_s((A), 200, 0, 200)
#define cpucycles() __builtin_readcyclecounter()
#endif  // NO_LIBUTIL
#endif  // UTILS_LIBUTIL_H
