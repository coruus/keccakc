#include "keccak/constructions/sponge.h"
#include "keccak/fips202/flags.h"
#include "keccak/fips202/sha3.h"
#include "keccak/modes/hash/hash-impl.h"
#include "keccak/rte/check-impl.h"
#include "libutil/libutil.h"

#include <stdint.h>
#include <stdlib.h>

#define HANDLE_ERR    \
  do {                \
    if (err == 0) {   \
      break;          \
    } else {          \
      SOFT_RTE(sha3); \
    }                 \
  } while (0)

/*@ behavior error:
      assumes sponge == \null;
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes sponge != \null;
      requires \valid(sponge);
      ensures \result == 0;
      ensures sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->flags, sponge->squeezed, sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int SHA3FN_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  int err = _hash_init(sponge, 200 - (DIGEST_LENGTH * 2), flag_SHA3FN ^ hash_absorbing);
  //@ assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate SHA3FN_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_SHA3FN ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes SHA3FN_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !SHA3FN_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->squeezed == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int SHA3FN_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = _hash_update(sponge, in, inlen, flag_SHA3FN ^ hash_absorbing);
  //@assert err == 0;
  HANDLE_ERR;
  return 0;
}

#define checkoutlen                \
  do {                             \
    if (outlen != DIGEST_LENGTH) { \
      SOFT_RTE(digestlen);         \
    }                              \
  } while (0)

/*@ predicate SHA3FN_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != DIGEST_LENGTH)
      || sponge->squeezed != 0 || sponge->flags != (flag_SHA3FN ^ hash_absorbing);
*/
/*@ behavior error:
      assumes SHA3FN_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !SHA3FN_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->squeezed, sponge->absorbed;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int SHA3FN_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  checkoutlen;
  checknull(sponge);
  checknull(out);

  int err = _hash_finalize(
      sponge, pad_sha, flag_SHA3FN ^ hash_absorbing, flag_SHA3FN ^ hash_squeezing);
  //@ assert err == 0;
  HANDLE_ERR;
  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output. TODO(dlg): Is this optimization-safe?
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, DIGEST_LENGTH, flag_SHA3FN ^ hash_squeezing);
  //@ assert err == 0;
  // Then clear the low bytes.
  memclear(sponge, 32 * 8);
  HANDLE_ERR;
  return 0;
}

/*@ predicate SHA3FN_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != DIGEST_LENGTH);
*/
/*@ behavior error:
      assumes SHA3FN_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !SHA3FN_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int SHA3FN(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  checknull(out);
  checknull(in);
  checkoutlen;

  keccak_sponge sponge;
  int err = 0;
  err = SHA3FN_init(&sponge);
  //@ assert(err == 0);
  HANDLE_ERR;
  err = SHA3FN_update(&sponge, in, inlen);
  //@ assert(err == 0);
  HANDLE_ERR;
  err = SHA3FN_digest(&sponge, out, outlen);
  //@ assert(err == 0);
  HANDLE_ERR;
  memclear(&sponge, sizeof(sponge));
  return err;
}
