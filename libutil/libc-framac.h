/* Definitions from the Frama-C standard library.
 * License: LGPL
 */
#ifdef __FRAMAC__
#ifndef LIBC_FRAMA_C
#define LIBC_FRAMA_C
#include <stdlib.h>
#undef memset
/*@ axiomatic MemSet {
  @ logic 𝔹 memset{L}(char *s, ℤ c, ℤ n);
  @ // reads s[0..n - 1];
  @ // Returns [true] iff array [s] contains only character [c]
  @
  @ axiom memset_def{L}:
  @   \forall char *s; \forall ℤ c; \forall ℤ n;
  @      memset(s,c,n) <==> \forall ℤ i; 0 <= i < n ==> s[i] == c;
  @ }
  @*/

/*@ requires \valid(((char*)s)+(0..n - 1));
  @ assigns ((char*)s)[0..n - 1] \from c;
  @ assigns \result \from s;
  @ ensures memset((char*)s,c,n);
  @ ensures \result == s;
  @*/
extern void* memset(void* s, int c, size_t n);

#endif  // LIBC_FRAMA_C
#endif  // __FRAMA_C__
