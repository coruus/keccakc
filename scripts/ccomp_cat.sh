#!/usr/bin/env sh
cat verification/compcert/string.c "$@" | 
gcc -arch i386 -U__GNUC__ -U__clang__ -U__BLOCKS__ \
  '-D__attribute__(x)=' -E -D__COMPCERT__ -UINLINE \
  -I/usr/local/lib/compcert -I keccak -I. -DNDEBUG -P -
