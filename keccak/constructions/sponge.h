#ifndef KECCAK_CONSTRUCTIONS_SPONGE_H
#define KECCAK_CONSTRUCTIONS_SPONGE_H

#include <string.h>
#include <stdlib.h>
#include <stdalign.h>
#include <stdint.h>
#include <stdbool.h>

/* The sponge structure. API users must treat it as an opaque blob.
 *
 * TODO: This may be an excessivly redundant structure. Directly
 * maintaining pointers would be better -- but could perhaps be
 * more dangerous to API consumers.
 */
typedef struct sponge {
  uint64_t a[25];
  // We reserve 7 bytes to be filled with random padding
  // (and, by chance, this preserves thirty-bit alignment).
  uint64_t padding[7];

  uint64_t absorbed;
  uint64_t squeezed;
  uint64_t rate;
  uint64_t flags;

} keccak_sponge;

/* The sponge invariant. (Note that a sponge is only allowed
   to be full or empty inside a function.)
*/
/*@ predicate sponge_invariant(keccak_sponge* sponge) =
  @      !((sponge->absorbed != 0) && (sponge->squeezed != 0))
  @   && (0 <= sponge->absorbed < sponge->rate)
  @   && (0 <= sponge->squeezed < sponge->rate)
  @   && (0 < sponge->rate < 200);
  @*/

/*@ predicate valid_sponge(keccak_sponge* sponge) =
  @      \valid(sponge->a+(0..24))
  @   && \valid(sponge)
  @   && \valid(&sponge->absorbed)
  @   && \valid(&sponge->squeezed)
  @   && \valid(&sponge->rate)
  @   && \valid( ((uint8_t*)(sponge->a))+(0..199) );
  */

/*@ logic integer cansqueeze(keccak_sponge* sponge) =
  @   sponge->rate - sponge->squeezed;
  @*/

static const size_t sponge_bytelen = 200;
#define sponge_bytelen 200
// for CompCert and other C99 tools

int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate);
/*@ assigns \nothing;
    behavior err:
      requires sponge == \null;
      ensures \result < 0;
    behavior inv_okay:
      requires sponge_invariant(sponge);
      ensures \result == 0;
    behavior inv_fail:
      requires !sponge_invariant(sponge);
      ensures \result < 0;
    complete behaviors;
    disjoint behaviors;
*/
int keccak_sponge_checkinv(register const keccak_sponge* const sponge);
/*@ requires sponge_invariant(sponge);
    ensures sponge_invariant(sponge);
*/
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t inlen);
/*@ requires sponge_invariant(sponge);
    ensures sponge_invariant(sponge);
*/
int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                          register uint8_t* const restrict out,
                          register const size_t outlen);

/* TODO(dlg)
size_t keccak_sponge_getrate(register keccak_sponge* const restrict sponge);
size_t keccak_sponge_getabsorbed(register keccak_sponge* const restrict sponge);
size_t keccak_sponge_getsqueezed(register keccak_sponge* const restrict sponge);
*/
#endif  // KECCAK_CONSTRUCTIONS_SPONGE_H
