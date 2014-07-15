#ifndef KECCAK_RTE_CHECK_IMPL_H
#define KECCAK_RTE_CHECK_IMPL_H
#include "keccak/rte/rte.h"
#include "keccak/rte/errors.h"

#define checknull(PTR)   \
  do {                   \
    if (PTR == NULL) {   \
      HARD_RTE(ptrnull); \
    }                    \
  } while (0)

#define HANDLE_ERR    \
  do {                \
    if (err == 0) {   \
      break;          \
    } else {          \
      SOFT_RTE(sha3); \
    }                 \
  } while (0)

#define checkoutlen                \
  do {                             \
    if (outlen != DIGEST_LENGTH) { \
      SOFT_RTE(digestlen);         \
    }                              \
  } while (0)

#endif
