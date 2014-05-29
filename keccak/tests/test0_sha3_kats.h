#ifndef KECCAK_TESTS_TEST0_SHA3_KATS_H
#define KECCAK_TESTS_TEST0_SHA3_KATS_H
#include <stdint.h>

static const uint8_t sha3_224_len0[28] = {
#include "test0-sha3-224-kat.txt"
};
static const uint8_t sha3_256_len0[32] = {
#include "test0-sha3-256-kat.txt"
};
static const uint8_t sha3_384_len0[48] = {
#include "test0-sha3-384-kat.txt"
};
static const uint8_t sha3_512_len0[64] = {
#include "test0-sha3-512-kat.txt"
};
#endif
