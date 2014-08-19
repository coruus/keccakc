#!/usr/bin/env python
# pylint: disable=invalid-name
from __future__ import division, print_function

import struct

from more_itertools import grouper
import parse
import yaml
import json

plen = parse.compile('Len = {}').parse
pmsg = parse.compile('Msg = {}').parse
pdigest = parse.compile('MD = {}').parse
psqueezed = parse.compile('Squeezed = {}').parse

pname = parse.compile('ShortMsg{}_{}.txt').parse

def pmd(message):
  """Parse an MD or Squeezed line."""
  parsed = pdigest(message)
  if parsed is None:
    parsed = psqueezed(message)
  return parsed

fnames = ['ShortMsgKAT_SHA3-224.txt',
          'ShortMsgKAT_SHA3-256.txt',
          'ShortMsgKAT_SHA3-384.txt',
          'ShortMsgKat_SHA3-512.txt',
          'ShortMsgKat_SHAKE128.txt',
          'ShortMsgKat_SHAKE256.txt']

ostruct = struct.Struct('HH')

def parse_kats(filename):
  lines = open(filename.split('.')[0] + '.recs').read().split('\n')[:-1]
  kats = {}
  for inlen, msg, md in grouper(3, lines):
    ilen = int(plen(inlen)[0])
    if (ilen % 8) != 0:
      continue
    msg = pmsg(msg)[0]
    md = pmd(md)[0]
    kats[ilen] = dict(message=msg, digest=md)
  return kats

if __name__ == '__main__':
  KATS = {}
  for filename in fnames:
    name = pname(filename)[1]
    KATS[name] = parse_kats(filename)

  with open('shortkats.yaml', 'wb') as f:
    f.write(yaml.dump(KATS, default_flow_style=False))
  json_kats = {}
  for katname, katvals in KATS.iteritems():
    json_kats[katname] = [{"length": k, "message": katvals[k]["message"], "digest": katvals[k]["digest"]}
                          for k in sorted(katvals.iterkeys())]
  with open('shortkats.json', 'wb') as f:
    f.write(json.dumps(json_kats, sort_keys=True, indent=2))
