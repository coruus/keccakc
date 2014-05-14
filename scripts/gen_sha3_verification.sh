#!/usr/bin/env sh
p=verification/frama-c
t=${p}/api_separate_sha3.template.c
sed -e 's/DIGEST_LENGTH/28/g;s/SHA3FN/sha3_224/g;' ${t} > ${p}/sha3_224.c
sed -e 's/DIGEST_LENGTH/32/g;s/SHA3FN/sha3_256/g;' ${t} > ${p}/sha3_256.c
sed -e 's/DIGEST_LENGTH/48/g;s/SHA3FN/sha3_384/g;' ${t} > ${p}/sha3_384.c
sed -e 's/DIGEST_LENGTH/64/g;s/SHA3FN/sha3_512/g;' ${t} > ${p}/sha3_512.c
