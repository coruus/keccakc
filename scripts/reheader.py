#!/usr/bin/env python
"""A simple Python script to update C header guards."""
from __future__ import division, print_function

import re

IFNDEF = re.compile(r'''#ifndef (\w+)''')
DEFINE = r'''#define {}$'''

filename = 'keccak/fips202/flags.h'
with open(filename) as f:
    lines = f.readlines()

newname = filename.replace('/', '_').replace('-', '_').replace('.', '_').upper()

print(newname)

match0 = IFNDEF.match(lines[0])
if match0 is not None:
    guard = match0.group(1)
    match1 = re.match(DEFINE.format(guard), lines[1])
    if match1 is not None:
            matches = re.findall(re.escape(guard))
            if matches != 2:
                print('too many matches')
            else:
                with open(filename) as f:
                    s = f.read()
                s = re.sub(re.escape(guard), re.escape(newname))
                with open(filename, 'wb') as f:
                    f.write(s)
        else:
            print('no match at end')
    else:
        print('no define')
else:
    print('no ifndef')

