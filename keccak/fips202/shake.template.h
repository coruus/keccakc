int SHAKEFN_init(register keccak_sponge* const restrict sponge);
int SHAKEFN_update(register keccak_sponge* const restrict sponge,
                   register const uint8_t* const restrict in,
                   register const size_t inlen);
int SHAKEFN_digest(register keccak_sponge* const restrict sponge,
                   register uint8_t* const restrict out,
                   register const size_t outlen);
int SHAKEFN(register uint8_t* const restrict out,
            register const size_t outlen,
            register const uint8_t* const restrict in,
            register const size_t inlen);
