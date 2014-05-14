int sha3_384_init(register keccak_sponge* const restrict sponge);
int sha3_384_update(register keccak_sponge* const restrict sponge,
                  register const uint8_t* const restrict in,
                  register const size_t inlen);
int sha3_384_digest(register keccak_sponge* const restrict sponge,
                  register uint8_t* const restrict out,
                  register const size_t outlen);
int sha3_384(register uint8_t* const restrict out,
           register const size_t outlen,
           register const uint8_t* const restrict in,
           register const size_t inlen);
