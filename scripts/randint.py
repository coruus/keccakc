#!/usr/bin/env python
"""Random hex integers; the default is 64 bits.

Usage:
  randint [-a] [-n <n>] [-b <b>]

Options:
  -a        format as array initializer [default: False]
  -n <n>    number of random values to print [default: 1]
  -b <b>    bit-length [default: 64]

"""
from __future__ import division, print_function

from os import urandom
from struct import unpack
import sys

from docopt import docopt


def c_rand(bitlen):
    """Return a C initializer for a single random value"""
    fmt = {8: 'B', 16: 'H', 32: 'I', 64: '<Q'}
    return ('UINT{bitlen}_C(0x{val:0{hexlen}x})'
            .format(hexlen=bitlen // 4, bitlen=bitlen,
                    val=unpack(fmt[bitlen], urandom(bitlen // 8))[0]))


def main(args):
    if args['-a']:
        print('{ ', end='')
        sep = ', '
    else:
        sep = '\n'
    bitlen = int(args['-b'])
    length = int(args['-n'])
    print(sep.join(c_rand(bitlen) for _ in range(length)), end='')
    if args['-a']:
        print(' }')
    else:
        print()

if __name__ == '__main__':
    args = docopt(__doc__, sys.argv[1:])
    try:
        main(args)
    except Exception as e:
        sys.stderr.write(str(e))
