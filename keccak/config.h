#ifndef __COMPCERT__
#define INLINE inline __attribute__((always_inline))
#define KINLINE
#else
#define INLINE inline
#define KINLINE
#endif
