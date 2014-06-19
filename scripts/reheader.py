#!/usr/bin/env python
"""An ugly Python script to update C header guards."""
from __future__ import division, print_function

import re
import sys

IFNDEF = re.compile(r'''#ifndef (\w+)''')
DEFINE = r'''#define {}$'''


def reheader(filename):
    """Update C header guards."""
    with open(filename) as f:
        s = f.read()

    lines = s.split('\n')

    newname = filename.replace(
        '/', '_').replace('-', '_').replace('.', '_').upper()

    print(newname)

    match0 = IFNDEF.match(lines[0])
    if match0 is not None:
        guard = match0.group(1)
        escaped = re.escape(guard)
        match1 = re.match(DEFINE.format(escaped), lines[1])
        if match1 is not None:
            matches = re.findall(re.escape(escaped), s)
            if len(matches) > 3:
                print('too many matches')
            else:
                s = re.sub(escaped, newname, s)
                with open(filename, 'wb') as f:
                    f.write(s)
        else:
            print('no match at end')
    else:
        print('no ifndef')

if __name__ == '__main__':
    reheader(sys.argv[1])
