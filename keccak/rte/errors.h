#ifndef KECCAK_RTE_ERRORS_H
#define KECCAK_RTE_ERRORS_H

#define E(NAME, NUMBER, STR)           \
  static const char* err_##NAME = STR; \
  static const int errno_##NAME = NUMBER

E(ptrnull, -1, "NULL passed as pointer");
E(rsize, -2, "size > RSIZE_MAX");
E(sponge_invariant, -3, "sponge invariant violated");
E(digestlen,
  -4,
  "SHA3 fixed-output-length functions must be called with outlen == digestlen");
E(sha3, -5, "error encountered in sha3 fixed-output-length function");
E(hash_flags, -6, "hash flags wrong");
E(hash_finalized, -7, "hash already finalized");
E(hash_not_finalized, -8, "hash not finalized");
E(hash_rate, -9, "rate of sponge differs from hash function rate");

#endif
