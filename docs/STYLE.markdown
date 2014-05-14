# Code conformance and style

## C files

### Standard-conformance

C language files must conform strictly to the C11 standard.

They must, in addition, not use any C11 features that are not supported
by CompCert. (This means, regrettably, that many C11-permitted uses for
`static const` globals are not allowed.)

All C files must be formatted with `clang-format -style=file`. A style
definition file is present in the repository root.

## Shell scripts

Shell scripts must be POSIX-compliant. The only non-POSIX commands
permitted are GNU sed and parallel.

## Python scripts

Must be Python 3 clean.

TODO(dlg): Automate compliance testing.
