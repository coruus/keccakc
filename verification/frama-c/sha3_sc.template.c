#include "keccak/fips202/sha3.h"

int main(void) {
  uint8_t in[200];
  for (size_t i = 0; i < 200; i++) {
    in[i] = Frama_C_interval(0, 255);
  }
  uint8_t out224[224 / 8];
  //  uint8_t out256[256 / 8];
  //  uint8_t out384[384 / 8];
  //  uint8_t out512[512 / 8];

  sha3_224(out224, 224 / 8, in, Frama_C_nondet(0, 200));
  //  sha3_256(out256, 256 / 8, in, Frama_C_interval(0, 200));
  //  sha3_384(out384, 384 / 8, in, Frama_C_interval(0, 200));
  //  sha3_512(out512, 512 / 8, in, Frama_C_interval(0, 200));
}

/*
-wlevel 5 -val-ilevel 32 -slevel 300 -plevel 250 -val-show-trace
-val-after-results
-val-callstack-results -slevel-merge-after-loop -val-split-return-auto -scf
-scf-allow-cast -value-verbose 2 -val-print-callstacks -metrics
-metrics-value-cover
-constfold -pp-annot -report -scg scg.dot -users -inout -input -out-external
-deref
-access-path -inout-callwise -journal-name verification/frama-c/journal.ml -save
verification/frama-c/analysis_context1.session -machdep x86_64 -constfold
-agressive-merging -val -then -val
*/
