#!/usr/bin/env python
from __future__ import division, print_function

S = '  buf[{}] = 0x{:02x};'
print('\n'.join(S.format(i, 0x9f) for i in range(200)))
