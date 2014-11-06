#ifndef KECCAK_CONFIG_H
#define KECCAK_CONFIG_H

#if defined(_WIN32)
#define MIN2(A, B) ((A < B) ? A : B)
#define memset_s(DST, DESTSIZE, VAL, COUNT) memset(DST, VAL, MIN2(DESTSIZE, COUNT))
#endif

#if !defined(__COMPCERT__) && !defined(__FRAMAC__) && !defined(_MSC_VER)
#define INLINE inline __attribute__((always_inline))
#define KINLINE
#elif defined(_MSC_VER)
#define INLINE
#define KINLINE
#else
#define INLINE inline
#define KINLINE
#endif  // !defined(__COMPCERT__) && !defined(__FRAMAC__)

// as project wide in CMakeLists.txt
//#define NO_LIBUTIL

#endif  // KECCAK_CONFIG_H
