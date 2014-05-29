#include "libutil/libutil.h"

#include <stdint.h>
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif
#if __has_builtin(__builtin_readcyclecounter)
uint64_t cpucycles(void) {
  return __builtin_readcyclecounter();
}
#elif defined(__x86_64__) && !defined __COMPCERT__
#include "libutil/tsc.h"
uint64_t cpucycles(void) {
  return tscm();
}
#else
#include <time.h>
uint64_t cpucycles(void) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  return tv_nsec + tv_sec * 1000000000L;
}
#endif
