add_library (keccak SHARED
             fips202/sha3.c fips202/shake.c constructions/sponge.c
             keccak/keccakf.c keccak/keccakf-1600/keccakf-opt64.c)
