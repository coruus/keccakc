#ifndef TSC_H
#define TSC_H
#include <stdint.h>

extern uint64_t tsc(void);
extern uint64_t tscp(void);
extern uint64_t tscm(void);

#endif  // DO_RDTSC_H
