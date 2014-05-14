#ifndef KECCAK_KECCAK_RC_1600_H
#define KECCAK_KECCAK_RC_1600_H
#include <stdint.h>

static const uint64_t round_constants[24] = {0x0000000000000001ULL,
                                             0x0000000000008082ULL,
                                             0x800000000000808aULL,
                                             0x8000000080008000ULL,
                                             0x000000000000808bULL,
                                             0x0000000080000001ULL,
                                             0x8000000080008081ULL,
                                             0x8000000000008009ULL,
                                             0x000000000000008aULL,
                                             0x0000000000000088ULL,
                                             0x0000000080008009ULL,
                                             0x000000008000000aULL,
                                             0x000000008000808bULL,
                                             0x800000000000008bULL,
                                             0x8000000000008089ULL,
                                             0x8000000000008003ULL,
                                             0x8000000000008002ULL,
                                             0x8000000000000080ULL,
                                             0x000000000000800aULL,
                                             0x800000008000000aULL,
                                             0x8000000080008081ULL,
                                             0x8000000000008080ULL,
                                             0x0000000080000001ULL,
                                             0x8000000080008008ULL};
#endif
