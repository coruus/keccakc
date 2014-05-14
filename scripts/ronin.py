#!/usr/bin/env python
"""Generate Ninja dependencies."""
from __future__ import division, print_function

from os.path import splitext
import re
import sys

LOCAL_INCLUDE_RE = re.compile(r'#include "(.*?)[.]h"')


def generate_buildlines(cfiles):
    """Generate Ninja build lines."""
    for filename in cfiles:
        with open(filename, 'rb') as f:
            s = f.read()
        includes = LOCAL_INCLUDE_RE.findall(s)
        deps = []
        for include in includes:
            source = include + '.c'
            header = include + '.h'
            if source in cfiles:
                deps.append(source)
            deps.append(header)
        print('build {f}.o: cc {f}.c | {deps}'
              .format(f=splitext(filename)[0], deps=' '.join(deps)))

if __name__ == '__main__':
    generate_buildlines(sys.argv[1:])
