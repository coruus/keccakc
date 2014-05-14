#include "keccak/constructions/sponge.h"
#include "keccak/fips202/flags.h"
#include "keccak/fips202/shake.h"
#include "keccak/modes/hash/hash-impl.h"
#include "libutil/libutil.h"

#include <stdint.h>
#include <stdlib.h>

int SHAKEFN_init(register keccak_sponge* const restrict sponge) {
  return _hash_init(sponge, 200 - (SECURITY_STRENGTH * 2), flag_SHAKEFN ^ hash_absorbing);
}

int SHAKEFN_update(register keccak_sponge* const restrict sponge,
                   register const uint8_t* const restrict in,
                   register const size_t inlen) {
  return _hash_update(sponge, in, inlen, flag_SHAKEFN ^ hash_absorbing);
}

int SHAKEFN_digest(register keccak_sponge* const restrict sponge,
                   register uint8_t* const restrict out,
                   register const size_t outlen) {
  int err = 0;
  if (sponge->flags == (flag_SHAKEFN ^ hash_absorbing)) {
    err = _hash_finalize(
        sponge, pad_shake, flag_SHAKEFN ^ hash_absorbing, flag_SHAKEFN ^ hash_squeezing);
    if (err != 0) {
      return err;
    }
  } else if (sponge->flags == (flag_SHAKEFN ^ hash_squeezing)) {
    return -1;
  }
  err = _hash_squeeze(sponge, out, outlen, flag_SHAKEFN ^ hash_squeezing);

  return err;
}

/*@ requires \valid(out+(0..outlen-1));
    requires \valid(in+(0..inlen-1));
    requires inlen < RSIZE_MAX;
    requires outlen < RSIZE_MAX;
    assigns out+(0..outlen-1);
    ensures \result == 0;
*/
int SHAKEFN(register uint8_t* const restrict out,
            register const size_t outlen,
            register const uint8_t* const restrict in,
            register const size_t inlen) {
  keccak_sponge sponge;
  int err = 0;
  err = SHAKEFN_init(&sponge);
  //@ assert(err == 0);
  err = SHAKEFN_update(&sponge, in, inlen);
  //@ assert(err == 0);
  err = SHAKEFN_digest(&sponge, out, outlen);
  //@ assert(err == 0);
  memclear(&sponge, sizeof(sponge));
  return err;
}
