#!/usr/bin/env python
from __future__ import division, print_function

from binascii import unhexlify

import parse
from more_itertools import grouper

plen = parse.compile('Len = {}').parse
pmsg = parse.compile('Msg = {}').parse
pdigest  = parse.compile('MD = {}').parse
psqueezed = parse.compile('Squeezed = {}').parse


def pmd(message):
    parse = pdigest(message)
    if parse is None:
        parse = psqueezed(message)
    return parse

fnames = ['ShortMsgKAT_SHA3-224.txt',
          'ShortMsgKAT_SHA3-256.txt',
          'ShortMsgKAT_SHA3-384.txt',
          'ShortMsgKat_SHA3-512.txt',
          'ShortMsgKat_SHAKE128.txt',
          'ShortMsgKat_SHAKE256.txt']
import struct
from os.path import splitext
ostruct = struct.Struct('HH')

def parse_kats(filename):
    lines = open(filename.split('.')[0] + '.recs').read().split('\n')[:-1]
    outtxt = []
    out = bytes()
    for inlen, msg, md in grouper(3, lines):
        r = [inlen, msg, md]
        ilen = int(plen(inlen)[0])
        if (ilen % 8) != 0:
            continue
        outtxt.extend([inlen, msg, md])
        msg = pmsg(msg)[0]
        md = pmd(md)[0]
        msg = unhexlify(msg)
        md = unhexlify(md)
        outlen = len(md)
        inlen = len(msg)
        out += ostruct.pack(inlen, outlen)
        out += msg
        out += md
    with open(filename.split('.')[0] + '.bin', 'wb') as f:
        f.write(out)
    return outtxt

out = []
for filename in fnames:
    out.extend(parse_kats(filename))

with open('kats_combined.txt', 'wb') as f:
    f.write('\n'.join(out))

