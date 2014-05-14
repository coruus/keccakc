#!/usr/bin/env sh
p=keccak/fips202/sha3
t=${p}/../sha3.template.c
h=${p}/../sha3.template.h
sed -e 's/DIGEST_LENGTH/28/g;s/SHA3FN/sha3_224/g;' ${t} > ${p}/sha3_224.c
sed -e 's/DIGEST_LENGTH/32/g;s/SHA3FN/sha3_256/g;' ${t} > ${p}/sha3_256.c
sed -e 's/DIGEST_LENGTH/48/g;s/SHA3FN/sha3_384/g;' ${t} > ${p}/sha3_384.c
sed -e 's/DIGEST_LENGTH/64/g;s/SHA3FN/sha3_512/g;' ${t} > ${p}/sha3_512.c
sed -e 's/SHA3FN/sha3_224/g;' ${h} > ${p}/sha3_224.h
sed -e 's/SHA3FN/sha3_256/g;' ${h} > ${p}/sha3_256.h
sed -e 's/SHA3FN/sha3_384/g;' ${h} > ${p}/sha3_384.h
sed -e 's/SHA3FN/sha3_512/g;' ${h} > ${p}/sha3_512.h
