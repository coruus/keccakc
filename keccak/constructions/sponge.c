#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "keccak/constructions/sponge-impl.h"
#include "keccak/constructions/sponge-ops.h"
#include "keccak/constructions/sponge.h"
#include "keccak/keccak/keccakf-1600.h"
#include "keccak/rte/check-impl.h"
#include "keccak/rte/rte.h"
#include "keccak/utils/c11shim.h"

int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate) {
  if (sponge == NULL) {
    HARD_RTE(ptrnull);
  }
  return _sponge_init(sponge, rate);
}

int keccak_sponge_checkinv(register const keccak_sponge* const sponge) {
  if (sponge == NULL) {
    HARD_RTE(ptrnull);
  }
  return _sponge_checkinv(sponge);
}

int keccak_sponge_pad(register keccak_sponge* const restrict sponge,
                      register const uint8_t dsbyte) {
  int err = 0;
  if (sponge == NULL) {
    HARD_RTE(ptrnull);
  }
  checkinv(sponge);
  _sponge_pad(sponge, dsbyte);
  /*@ assert err == 0; */
  return err;
}

#include "keccak/constructions/sponge-api.c"
