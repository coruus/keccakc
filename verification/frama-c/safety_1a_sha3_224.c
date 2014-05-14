#include "keccak/fips202/sha3.h"

#include <stdint.h>

#define maybe(STATEMENT)         \
  while (Frama_C_nondet(0, 1)) { \
    STATEMENT                    \
  }                              \
  do {                           \
  } while (0)
#define MAX 2147483646
#define range Frama_C_interval(0, 2147483646)
int main(void) {
  keccak_sponge sponge;
  memset(&sponge, 0, sizeof(sponge));
  uint8_t in[1];
  uint8_t out[1];

  // TODO(dlg): better solution than setting to zero?
  sponge.flags = 0;
  sponge.absorbed = range;
  sponge.squeezed = range;
  int err = 0;
  err = sha3_224_update(&sponge, &sponge, Frama_C_interval(0, 2147483646));
  //@ assert err < 0;
  err = sha3_224_update(&sponge, in, 1);
  //@ assert err < 0;
  err = sha3_224_update(&sponge, NULL, Frama_C_interval(0, 2147483646));
  //@ assert err < 0;
  int err2 = 0;
  err = sha3_224_digest(&sponge, NULL, Frama_C_interval(0, 2147483646));
  //@ assert err < 0;
  err = sha3_224_digest(&sponge, out, Frama_C_interval(0, 2147483646));
  //@ assert err < 0;
  err = sha3_224_digest(&sponge, NULL, 224 / 8);
  //@ assert err < 0;
  err = sha3_224_digest(&sponge, out, 224 / 8);
  //@ assert err < 0;
}
