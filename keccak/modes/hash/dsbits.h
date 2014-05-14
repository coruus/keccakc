#ifndef KECCAK_MODES_HASH_DSBITS_H
#define KECCAK_MODES_HASH_DSBITS_H
#include <stdint.h>

// little-endian *bit* ordering         2^ 01234567
static const uint8_t pad_end = 0x80;    // 00000001
static const uint8_t pad_shake = 0x1f;  // 11111000
static const uint8_t pad_sha = 0x06;    // 01100000
#endif                                  // KECCAK_MODES_HASH_DSBITS_H
