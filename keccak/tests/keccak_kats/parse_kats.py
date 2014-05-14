#!/usr/bin/env python
from __future__ import division, print_function

from binascii import unhexlify

import parse
from more_itertools import grouper

plen = parse.compile('Len = {}').parse
pmsg = parse.compile('Msg = {}').parse
pmd  = parse.compile('MD = {}').parse
psqeezed = parse.compi


fnames = [['ShortMsgKAT_SHA3-224.txt', 0],
          ['ShortMsgKAT_SHA3-256.txt', 1],
          ['ShortMsgKAT_SHA3-384.txt', 2],
          ['ShortMsgKat_SHA3-512.txt', 3],
          ['ShortMsgKat_SHAKE128.txt', 4],
          ['ShortMsgKat_SHAKE256.txt', 5]]
import struct
from os.path import splitext
ostruct = struct.Struct('BHH')

def parse_kats(filename, function):
    lines = open(filename + '.recs').read().split('\n')[:-1]
    out = bytes()
    for inlen, msg, md in grouper(3, lines):
        inlen = plen(inlen)[0]
        msg = pmsg(msg)[0]
        md = pmd(md)[0]
        if (int(inlen) % 8) != 0:
            continue
        msg = unhexlify(msg)
        md = unhexlify(md)
        outlen = len(md)
        inlen = len(msg)
        out += ostruct.pack(function, inlen, outlen)
        out += msg
        out += md
    with open(filename.split('.')[0] + '.bin', 'wb') as f:
        f.write(out)

for filename, function in fnames:
    parse_kats(filename, function)
