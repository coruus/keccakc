int shake128_init(register keccak_sponge* const restrict sponge);
int shake128_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int shake128_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);
int shake128(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
