# Tests

A number of these tests use macro magic. This is the only directory
where this is permissible.

## Test-vectors

Test-vector sources:
    - FIPS: NIST draft FIPS-202
    - KATS: Keccak Team KATs
      github.com/gvanas/KeccakCodePackage/TestVectors

TODO: Automate differential testing of test-vectors.

Current tests:
    - Zero-length message test (FIPS/KATS)
    - Byte-length message test (KATS)

## Benchmarks / stress tests


