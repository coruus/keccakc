#define KECCAK_PRIVATE_API
#include "keccak.h"

#include "keccak/constructions/sponge.h"
#include "keccak/constructions/sponge-ops.h"
#include "keccak/constructions/sponge-impl.h"
#include "keccak/fips202/flags.h"
#include "keccak/rte/check-impl.h"
#include "keccak/rte/rte.h"
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
  _sponge_init(sponge, 200 - (28 * 2));
  sponge->flags = flag_sha3_224 ^ hash_absorbing;
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
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 28))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_sha3_224 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
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
  int err = 0;
  if (outlen > 28) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_sha3_224 ^ hash_squeezing):
      SOFT_RTE(hash_finalized);
      return err;
    case (flag_sha3_224 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_sha);
      sponge->flags = flag_sha3_224 ^ hash_squeezing;
      break;
  }

  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  /*@ assert outlen < sponge->rate < spongelen; */
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return err;
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
  int err = 0;
  checknull(out);
  checknull(in);
  if (outlen > 28) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  err = sha3_224_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_224_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_224_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  state_scribble(&sponge);
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
  _sponge_init(sponge, 200 - (32 * 2));
  sponge->flags = flag_sha3_256 ^ hash_absorbing;
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
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 32))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_sha3_256 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
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
  int err = 0;
  if (outlen > 32) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_sha3_256 ^ hash_squeezing):
      SOFT_RTE(hash_finalized);
      return err;
    case (flag_sha3_256 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_sha);
      sponge->flags = flag_sha3_256 ^ hash_squeezing;
      break;
  }

  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  /*@ assert outlen < sponge->rate < spongelen; */
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return err;
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
  int err = 0;
  checknull(out);
  checknull(in);
  if (outlen > 32) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  err = sha3_256_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_256_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_256_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  state_scribble(&sponge);
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
  _sponge_init(sponge, 200 - (48 * 2));
  sponge->flags = flag_sha3_384 ^ hash_absorbing;
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
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 48))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_sha3_384 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
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
  int err = 0;
  if (outlen > 48) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_sha3_384 ^ hash_squeezing):
      SOFT_RTE(hash_finalized);
      return err;
    case (flag_sha3_384 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_sha);
      sponge->flags = flag_sha3_384 ^ hash_squeezing;
      break;
  }

  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  /*@ assert outlen < sponge->rate < spongelen; */
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return err;
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
  int err = 0;
  checknull(out);
  checknull(in);
  if (outlen > 48) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  err = sha3_384_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_384_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_384_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  state_scribble(&sponge);
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
  _sponge_init(sponge, 200 - (64 * 2));
  sponge->flags = flag_sha3_512 ^ hash_absorbing;
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
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 64))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_sha3_512 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
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
  int err = 0;
  if (outlen > 64) {
    SOFT_RTE(digestlen);
  }
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_sha3_512 ^ hash_squeezing):
      SOFT_RTE(hash_finalized);
      return err;
    case (flag_sha3_512 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_sha);
      sponge->flags = flag_sha3_512 ^ hash_squeezing;
      break;
  }

  // Clear the high bytes of the state -- which can never be output for the
  // FOFs -- before copying output (this ensures that, if used as a PMAC,
  // the key can't be recovered even if we abort due to error writing output).
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  /*@ assert outlen < sponge->rate < spongelen; */
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  // Then scribble the rest of the state.
  state_scribble(sponge);
  HANDLE_ERR;
  return err;
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
  int err = 0;
  checknull(out);
  checknull(in);
  if (outlen > 64) {
    SOFT_RTE(digestlen);
  }

  keccak_sponge sponge;
  err = sha3_512_init(&sponge);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_512_update(&sponge, in, inlen);  //@ assert(err == 0);
  HANDLE_ERR;
  err = sha3_512_digest(&sponge, out, outlen);  //@ assert(err == 0);
  HANDLE_ERR;
  state_scribble(&sponge);
  return err;
}



