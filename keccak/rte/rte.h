/* Header for defining runtime error states.
 *
 * These need to be macros; in production code, using HARD_RTE or SOFT_RTE
 * will always result in simply returning from the function. In testing,
 * it's useful to define them to abort.
 */
#ifndef KECCAK_RTE_RTE_H
#define KECCAK_RTE_RTE_H

#include "keccak/rte/errors.h"

#ifndef KECCAK_RTE_BYASSERT
#ifndef KECCAK_RTE_BYRETVAL
#define KECCAK_RTE_RETPRINT
#endif // KECCAK_RTE_BYRETVAL
#endif  // KECCAK_RTE_BYASSERT

#ifdef KECCAK_RTE_BYRETVAL

#define HARD_RTE(NAME)   \
  do {                   \
    return errno_##NAME; \
  } while (0)
#define SOFT_RTE(NAME)   \
  do {                   \
    return errno_##NAME; \
  } while (0)
#endif  // KECCAK_RTE_BYRETVAL

#ifdef KECCAK_RTE_RETPRINT
#include <stdio.h>
#define HARD_RTE(NAME)                                                        \
  do {                                                                        \
    fprintf(stderr, "%s:%u: hard rte: %s\n", __FILE__, __LINE__, err_##NAME); \
    return errno_##NAME;                                                      \
  } while (0)

#define SOFT_RTE(NAME)                                                        \
  do {                                                                        \
    fprintf(stderr, "%s:%u: soft rte: %s\n", __FILE__, __LINE__, err_##NAME); \
    return errno_##NAME;                                                      \
  } while (0)
#endif  // KECCAK_RTE_RETPRINT

#ifdef KECCAK_RTE_BYASSERT
#include <assert.h>
#include <stdio.h>

#define HARD_RTE(ERR)                                \
  do {                                               \
    printf("%s:%u: hard rte\n", __FILE__, __LINE__); \
    assert(0);                                       \
  } while (0)

#define SOFT_RTE(ERR)                                \
  do {                                               \
    printf("%s:%u: soft rte\n", __FILE__, __LINE__); \
    assert(0);                                       \
  } while (0)

#endif

#endif
