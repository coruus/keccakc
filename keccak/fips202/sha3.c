#define KECCAK_PRIVATE_API
#include "keccak.h"

#include "keccak/constructions/sponge.h"
#include "keccak/fips202/flags.h"
#include "keccak/modes/hash/hash-impl.h"
#include "keccak/rte/check-impl.h"
#include "libutil/libutil.h"

#include <stdint.h>
#include <stdlib.h>


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
int sha3_224_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  int err = _hash_init(sponge, 200 - (28 * 2), flag_sha3_224 ^ hash_absorbing);
  //@ assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_224_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_sha3_224 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes sha3_224_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_224_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->squeezed == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int sha3_224_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = _hash_update(sponge, in, inlen, flag_sha3_224 ^ hash_absorbing);
  //@assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_224_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 28)
      || sponge->squeezed != 0 || sponge->flags != (flag_sha3_224 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes sha3_224_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_224_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->squeezed, sponge->absorbed;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int sha3_224_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  if (outlen != 28) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_224 ^ hash_absorbing, flag_sha3_224 ^ hash_squeezing);
  //@ assert err == 0;
  HANDLE_ERR;
  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 28, flag_sha3_224 ^ hash_squeezing);
  //@ assert err == 0;
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_224_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 28);
*/
/*@ behavior error:
      assumes sha3_224_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_224_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int sha3_224(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  checknull(out);
  checknull(in);
  if (outlen != 28) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  int err = 0;
  err = sha3_224_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_224_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_224_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  memclear(&sponge, sizeof(sponge));
  return err;
}


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
int sha3_256_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  int err = _hash_init(sponge, 200 - (32 * 2), flag_sha3_256 ^ hash_absorbing);
  //@ assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_256_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_sha3_256 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes sha3_256_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_256_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->squeezed == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int sha3_256_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = _hash_update(sponge, in, inlen, flag_sha3_256 ^ hash_absorbing);
  //@assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_256_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 32)
      || sponge->squeezed != 0 || sponge->flags != (flag_sha3_256 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes sha3_256_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_256_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->squeezed, sponge->absorbed;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int sha3_256_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  if (outlen != 32) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_256 ^ hash_absorbing, flag_sha3_256 ^ hash_squeezing);
  //@ assert err == 0;
  HANDLE_ERR;
  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 32, flag_sha3_256 ^ hash_squeezing);
  //@ assert err == 0;
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_256_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 32);
*/
/*@ behavior error:
      assumes sha3_256_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_256_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int sha3_256(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  checknull(out);
  checknull(in);
  if (outlen != 32) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  int err = 0;
  err = sha3_256_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_256_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_256_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  memclear(&sponge, sizeof(sponge));
  return err;
}


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
int sha3_384_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  int err = _hash_init(sponge, 200 - (48 * 2), flag_sha3_384 ^ hash_absorbing);
  //@ assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_384_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_sha3_384 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes sha3_384_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_384_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->squeezed == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int sha3_384_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = _hash_update(sponge, in, inlen, flag_sha3_384 ^ hash_absorbing);
  //@assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_384_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 48)
      || sponge->squeezed != 0 || sponge->flags != (flag_sha3_384 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes sha3_384_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_384_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->squeezed, sponge->absorbed;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int sha3_384_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  if (outlen != 48) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_384 ^ hash_absorbing, flag_sha3_384 ^ hash_squeezing);
  //@ assert err == 0;
  HANDLE_ERR;
  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 48, flag_sha3_384 ^ hash_squeezing);
  //@ assert err == 0;
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_384_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 48);
*/
/*@ behavior error:
      assumes sha3_384_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_384_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int sha3_384(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  checknull(out);
  checknull(in);
  if (outlen != 48) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  int err = 0;
  err = sha3_384_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_384_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_384_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  memclear(&sponge, sizeof(sponge));
  return err;
}


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
int sha3_512_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  int err = _hash_init(sponge, 200 - (64 * 2), flag_sha3_512 ^ hash_absorbing);
  //@ assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_512_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_sha3_512 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes sha3_512_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_512_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->squeezed == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->absorbed;
    complete behaviors;
    disjoint behaviors;
*/
int sha3_512_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = _hash_update(sponge, in, inlen, flag_sha3_512 ^ hash_absorbing);
  //@assert err == 0;
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_512_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 64)
      || sponge->squeezed != 0 || sponge->flags != (flag_sha3_512 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes sha3_512_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_512_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->squeezed, sponge->absorbed;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int sha3_512_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  if (outlen != 64) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_512 ^ hash_absorbing, flag_sha3_512 ^ hash_squeezing);
  //@ assert err == 0;
  HANDLE_ERR;
  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 64, flag_sha3_512 ^ hash_squeezing);
  //@ assert err == 0;
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return 0;
}

/*@ predicate sha3_512_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 64);
*/
/*@ behavior error:
      assumes sha3_512_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !sha3_512_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int sha3_512(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  checknull(out);
  checknull(in);
  if (outlen != 64) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  int err = 0;
  err = sha3_512_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_512_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_512_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  memclear(&sponge, sizeof(sponge));
  return err;
}



