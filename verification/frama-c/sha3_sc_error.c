#include "keccak/fips202/sha3.h"

void* Frama_C_nondet_ptr(void* a, void* b);

#define BYTES (224 / 8)

#define FN(F) err = F(maybeout, outlen, maybein, inlen);

#define nd Frama_C_nondet
/*@ predicate p(int err, void* maybeout, size_t outlen, void* maybein, integer digestlen)
   =
      ((maybeout == \null) || (maybein == \null) || (outlen != digestlen))
      <==> (err < -1);
*/

int main(void) {
  uint8_t in[200];
  for (size_t i = 0; i < 200; i++) {
    in[i] = Frama_C_interval(0, 255);
  }
  uint8_t out[BYTES];
  //  uint8_t out256[256 / 8];
  //  uint8_t out384[384 / 8];
  //  uint8_t out512[512 / 8];

  uint8_t invalid;

  void* maybeout = Frama_C_nondet_ptr(&invalid, (void*)0);
  size_t outlen = nd(nd(nd(224 / 8, 256 / 8), nd(384 / 8, 512 / 8)), nd(0, 43));
  void* maybein = Frama_C_nondet_ptr(&invalid, (void*)0);
  size_t inlen = Frama_C_interval(0, 4294967295);
  /* TODO(dlg): This produces a clean result; but is semantically wrong.
     In particular, if outlen == digestlen, undefined behavior will be
     executed; Frama-C is incorrect to exclude non-termination in this case.
     (Or I am using the value analysis plugin incorrectly...)
   */

  int err = 0;
  int fn = Frama_C_interval(0, 3);
  switch (fn) {
    case 0:
      FN(sha3_224);
      // assert p(err, maybeout, outlen, maybein, ((int)24));
      //@assert err < 0;
      break;
    case 1:
      FN(sha3_256);
      //@assert err < 0;
      break;
    case 2:
      FN(sha3_384);
      //@assert err < 0;
      break;
    case 3:
      FN(sha3_512);
      //@assert err < 0;
      break;
  }
  //@assert err < 0;
  return err;
}
