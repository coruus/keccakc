# Verification strategy

## Properties we'd like to show (about the public API)

### Behavior on invalid input

Assume that the memory locations associated with the sponge parameters
are valid to read from. We'd like to show:

*Safety:* Invalid input (almost) surely results in error. (We can only
prove this probabilistically, because uninitialized memory could contain
fortuitously valid sponge parameters; the probability of this occurring
depends on whether memory is cleaned.)

*Memory write safety:* Invalid input (that results in error) does not write to
any memory locations.

*Memory read safety:* Over all execution paths that result in error, the set of
memory locations read is of minimal size (for a deterministic program).

(Only a non-determinstic program can access the minimal set *on
all* execution paths.)

### Behavior on valid input

These are somewhat harder:

*Safety:* Memory locations read and written are minimal and correct. No
undefined behavior is executed.

*Correctness:* The implementation produces correct output for all inputs.

## Verification strategy

*Compositional proof.* An implementation of SHA-3 can be divided into
two modules:

  - The Keccak-f[1600] permutation
  - The Sponge[pad, ..] construction

*Permutation.* Prove (for each implementation) that the set of memory
locations accessed is minimal, and that no undefined behavior is
executed.

*Sponge.* Prove that the sponge is implemented correctly. This is the
trickiest code.

# Tools

Instrumented concrete executions:

  - `compiler_rt`'s AddressSanitizer and UndefinedBehaviorSanitizer
  - valgrind
  - (TODO) SoftBound-CETS
