/usr/local/bin/frama-c -machdep x86_64 -pp-annot keccak/utils/xorinto-impl.h -wp -wp-model Typed+cast+cint -wp-invariants -wp-extensional -wp-timeout 10 -wp-print
