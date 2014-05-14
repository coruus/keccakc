#!/usr/bin/env sh
s="build/libutil.dylib keccak/constructions/sponge.c keccak/keccak/keccakf.c keccak/fips202/sha3/sha3_*.c keccak/fips202/shake/shake*.c"
kf="keccak/keccak/keccakf-1600"
kp="keccak/keccak/keccakp-1600"
t="keccak/tests"
impls="${kf}/keccakf-opt64.c ${kf}/keccakf-pygen.c ${kp}/keccakp-varopt64.c ${kp}/keccakp-tiny64.c"
parallel echo build '\$\{b\}'/{1/.}-{2/.}: cexec {1} {2} $s \
  ::: ${impls} \
  ::: $t/test0-sha3.c $t/test0-shake.c $t/test-kats.c > ninjas/buildlines.ninja
parallel echo build '\$\{b\}/bench-\$\{cc\}'-{1/.}-{2/.}: cexec_optim {1} {2} $s  \
  ::: ${impls} \
  ::: $(find keccak/tests -iname "bench*.c") >> ninjas/buildlines.ninja
