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

#endif
