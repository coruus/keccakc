int SHA3FN_init(register keccak_sponge* const restrict sponge);
int SHA3FN_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen);
int SHA3FN_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen);
int SHA3FN(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen);
