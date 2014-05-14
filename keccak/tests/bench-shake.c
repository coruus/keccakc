#include <assert.h>
#include <stdint.h>

#include "keccak/constructions/sponge.h"
#include "keccak/fips202/shake.h"
#include "keccak/tests/helpers-impl.h"
#include "keccak/tests/test-kats-input.h"
#include "libutil/tsc.h"

#define bench(LEN)                                       \
  do {                                                   \
    keccak_sponge sponge;                                \
    uint8_t out[LEN / 8] = {0};                          \
    shake##LEN##_init(&sponge);                          \
    uint64_t cycles = tscm();                            \
    double absorbed = 0;                                 \
    for (size_t i = 0; i < 32640; i++) {                 \
      shake##LEN##_update(&sponge, in + i, 32640 - i);   \
      absorbed += 32640 - i;                             \
    }                                                    \
    for (size_t i = 0; i < 32640; i++) {                 \
      shake##LEN##_update(&sponge, in + (32640 - i), i); \
      absorbed += i;                                     \
    }                                                    \
    shake##LEN##_digest(&sponge, out, (LEN / 8));        \
    printf("SHAKE%u absorbed %llub at %f cpb (",         \
           LEN,                                          \
           (uint64_t)absorbed,                           \
           (tscm() - cycles) / absorbed);                \
    printf("%x %x %x)\n", out[0], out[1], out[2]);       \
  } while (0)

int main(void) {
  bench(128);
  bench(256);
}
