#!/usr/bin/env python
from __future__ import division, print_function

from binascii import unhexlify

import parse
from more_itertools import grouper

plen = parse.compile('Len = {}').parse
pmsg = parse.compile('Msg = {}').parse
pmd  = parse.compile('MD = {}').parse


def parse_katsins(filename):
    lines = open(filename + '.recs').read().split('\n')[:-1]
    out = bytes()
    for inlen, msg, md in grouper(3, lines):
        inlen = plen(inlen)[0]
        msg = pmsg(msg)[0]
        md = pmd(md)[0]
        if (int(inlen) % 8) != 0:
            continue
        msg = unhexlify(msg)
        print(int(inlen) // 8, len(msg))
        out += msg
    with open(filename.split('.')[0] + '.bin', 'wb') as f:
        f.write(out)
    return out

filename = "ShortMsgKAT.txt"
out = parse_katsins(filename)
