#!/usr/bin/env sh
srcfiles="keccak/keccak/keccakf.c keccak/keccak/keccakf-1600.h keccak/keccak/keccak-1600.h \
   keccak/constructions/sponge* keccak/modes/hash/hash-impl.h \
   keccak/fips202/sha3.h keccak/fips202/sha3.template.c keccak/fips202/sha3.template.h \
   keccak/fips202/shake.h keccak/fips202/shake.template.c keccak/fips202/shake.template.h \
   keccak/fips202/flags.h keccak/modes/hash/dsbits.h \
   keccak/rte/rte.h keccak/utils/c11shim.h keccak/utils/xorinto-impl.h"
/usr/bin/env echo "cloc:"
cloc ${srcfiles} | tail -n +6
/usr/bin/env echo -n "c_count: "
c_count ${srcfiles} | tail -1
