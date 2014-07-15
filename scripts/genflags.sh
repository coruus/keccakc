#!/usr/bin/env sh
printf "\n// Flags indicating sponge state\n"
s="hash_absorbing hash_squeezing"
parallel -k ./scripts/mkk.py "libkeccakc" "{}" ::: ${s}
printf "\n// FIPS-202 modes of operation\n"
f="sha3_224 sha3_256 sha3_384 sha3_512 shake128 shake256"
parallel -k ./scripts/mkk.py "libkeccakc" "flag_{}" ::: ${f}
printf "\n// Extended modes of operation\n"
e="shake192 shake224 shake384 shake512"
parallel -k ./scripts/mkk.py "libkeccakc" "flag_{}" ::: ${e}
printf "\n"
