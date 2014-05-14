#include "keccak/fips202/sha3.h"

int main(void) {
  uint8_t in[200];
  for (size_t i = 0; i < 200; i++) {
    in[i] = Frama_C_interval(0, 255);
  }
  int err = 0;
  uint8_t out[BITS];
  keccak_sponge sponge;
  err = SHA3FN_init(&sponge);
  //@ assert err == 0;
  err = SHA3FN_update(&sponge, in, Frama_C_interval(0, 200));
  //@ assert err == 0;
  err = SHA3FN_digest(&sponge, out, BITS / 8);
  //@ assert err == 0;
  return err;
}
