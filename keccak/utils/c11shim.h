#ifndef C11SHIM_H
#define C11SHIM_H
/* Shims to make C11 code work with various C99 analysis tools. */

#define SHIM_ANNEX_UNSAFE

// RSIZE_MAX is defined in stdint.h
#include <stdint.h>

#ifndef RSIZE_MAX
#define RSIZE_MAX (SIZE_MAX >> 1)
#endif  // RSIZE_MAX

// Since we can't easily check for typedefs, we unconditionally define
// preprocessor macros for them.
//
// TODO(dlg): Do any non-C11-conformant systems define
// RSIZE_MAX by default but not rsize_t?
#define rsize_t size_t
#define errno_t int

#ifdef SHIM_ANNEX_UNSAFE
#include <string.h>

#define MIN2(A, B) ((A < B) ? A : B)
#define MIN3(A, B, C) (MIN2(MIN2(A, B), C))

/* These are some (unsafe) shims for C11 Annex 1 functions.
 *
 * Note that they are not C11 compliant; in particular, the standard requires
 * that, even if defined as a macro, it must be possible to obtain a function
 * pointer to the function. (And sizes greater than RSIZE_MAX aren't handled;
 * this is at the moment because it complicates analysis......)
 *
 * memset_s MUST NOT be shimmed like this; its semantics cannot be approximated
 * by any other function.
*/
#define memcpy_s(DST, DSTLEN, SRC, SRCLEN, OPLEN) \
  memcpy(DST, SRC, MIN3(DSTLEN, SRCLEN, OPLEN))
#define memcmp_s(A, ALEN, B, BLEN, OPLEN) memcmp(A, B, MIN3(ALEN, BLEN, OPLEN))
#endif  // SHIM_ANNEX_TO_UNSAFE

#endif  // C11SHIM_H
