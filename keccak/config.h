#ifndef KECCAK_CONFIG_H
#define KECCAK_CONFIG_H
#if !defined(__COMPCERT__) && !defined(__FRAMAC__)
#define INLINE inline __attribute__((always_inline))
#define KINLINE
#else
#define INLINE inline
#define KINLINE
#endif  // !defined(__COMPCERT__) && !defined(__FRAMAC__)
#endif  // KECCAK_CONFIG_H
