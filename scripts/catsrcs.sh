impl="keccak/keccak/keccakf-1600/keccakf-opt64.c"
s="keccak/constructions/sponge.c keccak/keccak/keccakf.c  keccak/fips202/sha3/sha3_*.c keccak/fips202/shake/shake*.c libutil/memclear.c"
defs="-D__STDC_WANT_ANNEX_1=1 -D__COMPCERT__ -DKECCAK_RTE_BYRETVAL"
mach="-D__x86_64__"
opts="-undef -std=c11 -I. -Ikeccak -P"
cat $impl $s | cpp-4.8 ${opts} ${defs} ${mach} - > cat.64.c
mach="-D__i386__"
cat $impl $s | cpp-4.8 ${opts} ${defs} ${mach} - > cat.32.c
