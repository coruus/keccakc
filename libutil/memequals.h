# 1 "libutil/memequals.h.in"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 170 "<built-in>" 3
# 1 "<command line>" 1
# 1 "libutil/memequals.macros" 1
# 2 "<command line>" 2

# 1 "<built-in>" 2
# 1 "libutil/memequals.h.in" 2
#ifndef LIBUTIL_MEMEQUALS_H
#define LIBUTIL_MEMEQUALS_H

#include "libutils/config.h"

#include <stdint.h>
#include <stdlib.h>

size_t memequals##8(const void* const src, const uint##8##_t val, const size_t len);
size_t memequals##16(const void* const src, const uint##16##_t val, const size_t len);
size_t memequals##32(const void* const src, const uint##32##_t val, const size_t len);
size_t memequals##64(const void* const src, const uint##64##_t val, const size_t len);

#ifdef LIBUTIL_GENERICS
#define vequals(buf, val, len)                           \
  \ _Generic((val), uint8_t                              \
             : memequals8(buf, val, len),     \ uint16_t \
             : memequals16(buf, val, len),   \ uint32_t  \
             : memequals32(buf, val, len), uint64_t      \
             :                                           \
             : memequals64(buf, val, len))

#endif  // LIBUTIL_GENERICS

#endif  // LIBUTIL_MEMEQUALS_H
