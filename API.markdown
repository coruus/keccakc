# API notes

The public API is completely defined by the top-level `keccak.h` file.
The use of any other functions, even if exported, is unsupported; it is
likely that the internal API will change substantially.

## Serialization of sponges

Serialization of FIPS-202-defined instances is not supported; API users
must treat the structures as opaque. (If you think that you need to
serialize an SHA-3 or SHAKE sponge-state, you're probably doing it wrong.)

TODO(dlg): Serialization of generic sponge instances is supported,
provided that the functions `sponge_serialize` and `sponge_deserialize`
are used.

Neither this implementation nor C11 guarantees
that, where `dest` is a contiguous memory region of length `sizeof(sponge)`:
`memcpy(dest, sponge, sizeof(sponge))` will produce the same behavior for
two different translations.
