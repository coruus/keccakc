p=keccak
sha3=$p/fips202/sha3
shake=$p/fips202/shake
cat \
  $p/constructions/sponge.c $p/keccak/keccakf-1600/keccakf-tiny.c \
  $p/keccak/keccakf.c \
  $sha3/sha3_224.c $sha3/sha3_256.c $sha3/sha3_384.c $sha3/sha3_512.c \
  $shake/shake128.c $shake/shake256.c
