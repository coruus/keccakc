#ifndef UTILS_LIBUTIL_H
#define UTILS_LIBUTIL_H

#include <stdlib.h>
#ifndef NO_LIBUTIL
extern void memclear(void* const, const size_t);
extern void state_scribble(void* const);
extern void state_clear(void* const);
extern uint64_t cpucycles(void);
#elif defined(_MSC_VER)
#include <intrin.h>
#pragma intrinsic(__rdtsc)
#define memclear(DST, LEN) memset((DST), 0, (LEN))
#define state_scribble(A) memset((A), 0xc1, 200)
#define state_clear(A) memset((A), 0, 200)
#define cpucycles() __rdtsc()
#else
#include <string.h>
#define memclear(DST, LEN) memset_s((DST), (LEN), 0, (LEN))
#define state_scribble(A) memset_s((A), 200, 0xc1, 200)
#define state_clear(A) memset_s((A), 200, 0, 200)
#define cpucycles() __builtin_readcyclecounter()
#endif  // NO_LIBUTIL

#endif  // UTILS_LIBUTIL_H
