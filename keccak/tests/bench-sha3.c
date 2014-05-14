#include <assert.h>
#include <stdint.h>

#include "keccak/constructions/sponge.h"
#include "keccak/fips202/sha3.h"
#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test-kats-input.h"
#include "libutil/tsc.h"

#define bench(DIGESTLEN)                                       \
  do {                                                         \
    keccak_sponge sponge;                                      \
    uint8_t out[DIGESTLEN / 8] = {0};                          \
    sha3_##DIGESTLEN##_init(&sponge);                          \
    uint64_t cycles = tscm();                                  \
    double absorbed = 0;                                       \
    for (size_t i = 0; i < 32640; i++) {                       \
      sha3_##DIGESTLEN##_update(&sponge, in + i, 32640 - i);   \
      absorbed += 32640 - i;                                   \
    }                                                          \
    for (size_t i = 0; i < 32640; i++) {                       \
      sha3_##DIGESTLEN##_update(&sponge, in + (32640 - i), i); \
      absorbed += 32640 - i;                                   \
    }                                                          \
    sha3_##DIGESTLEN##_digest(&sponge, out, (DIGESTLEN / 8));  \
    printf("SHA3-%u absorbed %llub at %f cpb (",               \
           DIGESTLEN,                                          \
           (uint64_t)absorbed,                                 \
           (tscm() - cycles) / absorbed);                      \
    printf("%x %x %x)\n", out[0], out[1], out[2]);             \
  } while (0)

int main(void) {
  bench(224);
  bench(256);
  bench(384);
  bench(512);
}
