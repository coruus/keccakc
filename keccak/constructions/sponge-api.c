
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t len) {
  int err = 0;
  if ((in == NULL) || (len > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  _sponge_absorb(sponge, in, len);
  /*@ assert err == 0; */
  return err;
}
int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                         register uint8_t* const restrict out,
                         register const size_t len) {
  int err = 0;
  if ((out == NULL) || (len > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  _sponge_squeeze(sponge, out, len);
  /*@ assert err == 0; */
  return err;
}
int keccak_sponge_squexor(register keccak_sponge* const restrict sponge,
                         register uint8_t* const restrict out,
                         register const size_t len) {
  int err = 0;
  if ((out == NULL) || (len > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  _sponge_squexor(sponge, out, len);
  /*@ assert err == 0; */
  return err;
}
int keccak_sponge_absqueeze(register keccak_sponge* const restrict sponge,
                         register uint8_t* const restrict io,
                         register const size_t len) {
  int err = 0;
  if ((io == NULL) || (len > RSIZE_MAX)) {
    HARD_RTE(rsize);
  }
  checkinv(sponge);
  _sponge_absqueeze(sponge, io, len);
  /*@ assert err == 0; */
  return err;
}

