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
      assigns sponge->a[0..24], sponge->flags, sponge->position, sponge->position;
    complete behaviors;
    disjoint behaviors;
*/
int shake128_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  _sponge_init(sponge, 200 - (16 * 2));
  sponge->flags = flag_shake128 ^ hash_absorbing;
  return 0;
}

/*@ predicate shake128_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_shake128 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes shake128_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !shake128_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->position == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->position;
    complete behaviors;
    disjoint behaviors;
*/
int shake128_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 16))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_shake128 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
}

/*@ predicate shake128_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 16)
      || sponge->position != 0 || sponge->flags != (flag_shake128 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes shake128_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !shake128_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->position, sponge->position;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int shake128_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  int err = 0;
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_shake128 ^ hash_squeezing):
      break; 
    case (flag_shake128 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_shake);
      sponge->flags = flag_shake128 ^ hash_squeezing;
      break;
  }
  
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  
  HANDLE_ERR;
  return err;
}

/*@ predicate shake128_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 16);
*/
/*@ behavior error:
      assumes shake128_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !shake128_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int shake128(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  int err = 0;
  checknull(out);
  checknull(in);

  keccak_sponge sponge;
  err = shake128_init(&sponge); 
  /* @ assert(err == 0); */
  HANDLE_ERR;
  err = shake128_update(&sponge, in, inlen);
  /*@ assert(err == 0); */
  HANDLE_ERR;
  err = shake128_digest(&sponge, out, outlen); 
  /*@ assert(err == 0); */
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
      assigns sponge->a[0..24], sponge->flags, sponge->position, sponge->position;
    complete behaviors;
    disjoint behaviors;
*/
int shake256_init(register keccak_sponge* const restrict sponge) {
  checknull(sponge);
  _sponge_init(sponge, 200 - (32 * 2));
  sponge->flags = flag_shake256 ^ hash_absorbing;
  return 0;
}

/*@ predicate shake256_update_err(keccak_sponge* sponge, uint8_t* in) =
      (sponge == \null) || (in == \null) || (sponge->flags != (flag_shake256 ^
   hash_absorbing));
*/
/*@ behavior error:
      assumes shake256_update_err(sponge, in);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !shake256_update_err(sponge, in);
      requires \valid(sponge) && \valid_read(in+(0..inlen-1));
      requires sponge->position == 0;
      ensures \result == 0;
      ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
      assigns sponge->a[0..24], sponge->position;
    complete behaviors;
    disjoint behaviors;
*/
int shake256_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen) {
  checknull(sponge);
  checknull(in);
  int err = 0;
  checkinv(sponge);
  if (sponge->rate != (200 - (2 * 32))) {
     SOFT_RTE(hash_rate);
  } else if (sponge->flags != (flag_shake256 ^ hash_absorbing)) {
     SOFT_RTE(hash_flags);
  }
  _sponge_absorb(sponge, in, inlen);
  return err;
}

/*@ predicate shake256_digest_err(keccak_sponge* sponge, uint8_t* out, size_t outlen) =
      (sponge == \null) || (out == \null) || (outlen != 32)
      || sponge->position != 0 || sponge->flags != (flag_shake256 ^ hash_absorbing);
*/
/*@ behavior error:
      assumes shake256_digest_err(sponge, out, outlen);
      ensures \result == 0;
      assigns \nothing;
    behavior success:
      assumes !shake256_digest_err(sponge, out, outlen);
      requires \valid(out+(0..outlen-1));
      ensures \result == 0;
      assigns sponge->a[0..24], sponge->position, sponge->position;
      //ensures \old(sponge_invariant(sponge)) ==> sponge_invariant(sponge);
   complete behaviors;
   disjoint behaviors;
*/
int shake256_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen) {
  int err = 0;
  checknull(sponge);
  checknull(out);

  checkinv(sponge);
  switch (sponge->flags) {
    case (flag_shake256 ^ hash_squeezing):
      break; 
    case (flag_shake256 ^ hash_absorbing):
      // If we're still absorbing, pad the message and apply Keccak-f.
      _sponge_pad(sponge, pad_shake);
      sponge->flags = flag_shake256 ^ hash_squeezing;
      break;
  }
  
  _sponge_squeeze(sponge, out, outlen);
  /*@ assert err == 0; */
  
  HANDLE_ERR;
  return err;
}

/*@ predicate shake256_sc_err(uint8_t* out, size_t outlen, uint8_t* in, size_t inlen) =
      (in == \null) || (out == \null) || (outlen != 32);
*/
/*@ behavior error:
      assumes shake256_sc_err(out, outlen, in, inlen);
      ensures \result < 0;
      assigns \nothing;
    behavior success:
      assumes !shake256_sc_err(out, outlen, in, inlen);
      requires \valid(out+(0..outlen-1)) && \valid(in+(0..inlen-1));
      ensures \result == 0;
      assigns out[0..outlen-1];
    complete behaviors;
    disjoint behaviors;
*/
int shake256(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen) {
  int err = 0;
  checknull(out);
  checknull(in);

  keccak_sponge sponge;
  err = shake256_init(&sponge); 
  /* @ assert(err == 0); */
  HANDLE_ERR;
  err = shake256_update(&sponge, in, inlen);
  /*@ assert(err == 0); */
  HANDLE_ERR;
  err = shake256_digest(&sponge, out, outlen); 
  /*@ assert(err == 0); */
  HANDLE_ERR;
  state_scribble(&sponge);
  return err;
}




