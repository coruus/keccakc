/** A simple authenticated encryption mode. */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "keccak.h"

/** ShakeWrap[r]: This function is its own inverse; check that the
 * ciphertext is authentic by verifying that tag is 0 after decryption.
 */
int keccak_shakewrap(register const uint8_t* const restrict key,
                     register const uint8_t* const restrict keylen,
                     register const uint8_t* const restrict ad,
                     register const uint8_t* const restrict adlen,
                     register uint8_t* const restrict buf,
                     register uint8_t* const restrict buflen,
                     register uint8_t* const restrict tag,
                     register const size_t taglen,
                     register const size_t rate) {
  keccak_sponge sponge;
  checkrsize(taglen);
  checkbuf(key);
  checkbuf(ad);
  checkbuf(in);
  checkbuf(out);
  int err = keccak_sponge_init(&sponge, rate);
  assert(err == 0);
  keccak_sponge_absorb(&sponge, key, keylen);
  keccak_sponge_pad(&sponge, 0x01);
  keccak_sponge_absorb(&sponge, ad, adlen);
  keccak_sponge_pad(&sponge, 0x03);
  keccak_sponge_absqueeze(&sponge, buf, buflen);
  keccak_sponge_pad(&sponge, 0x1f);
  keccak_sponge_squexor(&sponge, tag, taglen);
  memset_s(&sponge, sizeof(sponge), 0, sizeof(sponge));
}
