# C11-clean SHA-3 and SHAKE

An implementation of the [`Keccak-f[1600]` permutation][keccak_site],
[draft FIPS-202][fips202_site] (SHA-3 and SHAKE), and (eventually)
the stream cipher and DRBG constructions from the Keccak Team's
"Cryptographic Sponge Functions v0.1".

The goal of this implementation is formal verification of the C
code.

This is an alpha release; it has only been (very partially)
verified.

## Introduction

Design criteria:

- Simple API
- Simple design
- Lowest sloc possible
- Pluggable choice of permutation implementation
- Safe to incorporate in source form into client code (i.e.,
  strict conformance with the C11 standard)
- Built-in-self-tests

### Trade-offs

It trades support for big-endian platforms and arbitrary bit-length
messages for simplicity; I think this is a worthwhile tradeoff to
make. (If you have a big-endian platform to test on, however, I
am happy to accept pull requests in `keccak/keccak` to implement
support.)

It trades some simplicity to get verification tools to work. This
is not a worthwhile tradeoff; it is a bug (perhaps mine, perhaps
the tools').

### Credits

Mad props to Guido Bertoni, Joan Daemen, Michaël Peeters,
and Gilles Van Assche for the very beautiful Keccak permutation,
and the incredibly useful sponge construction.

And also mad props to Ronny Van Keer, whose charming assembler
implementations of Keccak introduced me to the permutation.

The opt64 and varopt64 implementations of the permutation are
entirely their work (plus CPP and clang-format).

### Notes

This code is not endorsed by the Keccak Team or, in fact,
anyone else. The official Keccak code package can be found at
https://github.com/gvanas/KeccakCodePackage

I, regrettably, cannot say that I endorse their code. In particular,
it executes undefined behaviors, and is therefore unsafe to include
in a source tree with functions which are clients of its interface.

(I have contributed some patches to their repo, which have been
accepted; but these are insufficient. On studying thir code, I felt
that the best way to understand their mistakes was to make my own.
Thus this repository; and thus all the verification stuff.)

### License

3BSD at present; if you need CC0, email me.

## Warning

Please don't use this code for anything other than testing at
the moment; I will tag a release when I have sufficient confidence
that the code is safe and correct.

Note, especially, that there are no test cases for SHAKE with
non-zero input length at present.

## Building

To build this project, become a daimyo. You will then have enough
[ninjas][ninja_home].

Run ninja in the root; if it doesn't work, fix-up the ninja files,
and file a pull request with your build environment.
(Your changes don't have to be pretty; I'll do that work.)

The library *should* build in any C11-compliant environment that
provides the `memcpy` and `memset` functions.

The tests require a hosted environment at present; they use `stdio.h`.
I consider this a bug.

## Verification overview

Tools used:

- Clang's [AddressSanitizer][asan] and [UndefinedBehaviorSanitizer][ubsan] runtimes
- [Frama-C][framac_site]'s Value Analysis and Weakest Preconditions
  plugins
- [CompCert][compcert_site]
- (TODO) Valgrind

Tools under consideration:

- [Vellvm][vellvm_site]
- [CBMC][cbmc_site]
- [Klee][klee_repo]
- [VST][vst_site]

Done so far:

1. Asan and Ubsan-clean over concrete executions.

2. CompCert interpreter traces over concrete executions as proof of
freedom from (CompCert-)undefined behavior

3. Frama-C's value analysis plugin over set of symbolic executions
   (see the verification/frama-c directory for the latest analysis
   logs)

In progress:

- Proofs of safety and termination (assuming validity) using
  Frama-C's [Weakest Preconditions Plug-in][wp_site]

Thinking about:

- How to prove correctness of implementation


## Tests and metrics

### Tests

TODO: Automating the test harnesses.

Build the project. Tests for each permutation implementation will be
present in the `build` directory. Do, e.g.,

   % ./build/keccakf-opt64-test0-sha3
   Len = 0
   Msg = 00
   MD = 6B4E03423667DBB73B6E15454F0EB1ABD4597F9A1B078E3F5B5A6BC7
   SHA3-224(''): OKAY
   Len = 0
   Msg = 00
   MD = A7FFC6F8BF1ED76651C14756A061D662F580FF4DE43B49FA82D80A4B80F8434A
   SHA3-256(''): OKAY
   Len = 0
   Msg = 00
   MD = 0C63A75B845E4F7D01107D852E4C2485C51A50AAAA94FC61995E71BBEE983A2AC3713831264ADB47FB6BD1E058D5F004
   SHA3-384(''): OKAY
   Len = 0
   Msg = 00
   MD = A69F73CCA23A9AC5C8B567DC185A756E97C982164FE25859E0D1DCC1475C80A615B2123AF1F5F94C11E3E9402C3AC558F500199D95B6D3E301758586281DCD26
   SHA3-512(''): OKAY

Te following files will contain CompCert's output in interpreter
mode for the zero-length test-cases:

    verification/compcert/test0-sha3-opt64.trace
    verification/compcert/test0-shake-opt64.trace

If you do `tail -1`, you should see:

    % tail -1 verification/compcert/test0-sha3-opt64.trace
    Time 284063: program terminated (exit code = 0)
    % tail -1 verification/compcert/test0-shake-opt64.trace
    Time 550189: program terminated (exit code = 0)

(The files contain the output as well.)

### Lines of code

`scripts/count.sh` computes the sloc metric for this project. Current
value: 549.

    % c_count \
        keccak/keccak/keccakf.c keccak/keccak/keccakf-1600.h keccak/keccak/keccak-1600.h \
        keccak/constructions/sponge* keccak/modes/hash/hash-impl.h \
        keccak/fips202/sha3.h keccak/fips202/sha3.template.c keccak/fips202/sha3.template.h \
        keccak/fips202/shake.h keccak/fips202/shake.template.c keccak/fips202/shake.template.h \
        keccak/fips202/flags.h keccak/modes/hash/dsbits.h \
        keccak/rte/rte.h keccak/utils/c11shim.h keccak/utils/xorinto-impl.h | tail -1

Go's implementation (SHA-3 only). Value: 144

    % c_count ~/go/src/code.google.com/p/go.crypto/sha3/sha3.go

Target sloc: `sloc(go) * 2 == 288`

### Undefined behavior

This code attempts to avoid undefined behavior. [Xi Wang][xiw]
has several papers about why undefined behavior is dangerous in
security-critical code, e.g., ["Undefined behavior: What happened to my code?"](http://pdos.csail.mit.edu/~xi/papers/ub-apsys12.pdf).

Any dynamic or static behavior that is undefined under either the C99
or C11 standard is a bug; pull requests eagerly accepted.

[keccak_site]: http://keccak.noekeon.org/
[ninja_home]: http://martine.github.io/
[fips202_site]: http://csrc.nist.gov/groups/ST/hash/sha-3/sha-3_standardization.html
[clang_manual]: http://clang.llvm.org/docs/UsersManual.html
[cbmc_site]: http://www.cprover.org/cbmc/
[framac_site]: http://www.frama-c.com/
[vellvm_site]: http://www.cis.upenn.edu/~stevez/vellvm/
[klee_repo]: https://github.com/klee/klee
[asan]: http://clang.llvm.org/docs/AddressSanitizer.html
[ubsan]: http://clang.llvm.org/docs/UsersManual.html
[vst_site]: http://vst.cs.princeton.edu/
[compcert_site]: http://compcert.inria.fr/
[wp_site]: http://frama-c.com/wp.html
[xiw]: http://kqueue.org/papers/
