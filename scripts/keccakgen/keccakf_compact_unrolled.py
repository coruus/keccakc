"""Generate C code for fully unrolled Keccak-f[1600] permutation.

   (Essentially an unrolled version of the compact Keccak code.)

   Written by: David Leon Gil

   Inspired by: Eric Roshan-Eisner's implementation in Go. See
   https://code.google.com/p/go/source/browse/sha3/keccakf.go
   and https://bitbucket.org/ede/sha3

   License: 3BSD
"""
from __future__ import division, print_function

RC = [0x0000000000000001, 0x0000000000008082, 0x800000000000808A,
      0x8000000080008000, 0x000000000000808B, 0x0000000080000001,
      0x8000000080008081, 0x8000000000008009, 0x000000000000008A,
      0x0000000000000088, 0x0000000080008009, 0x000000008000000A,
      0x000000008000808B, 0x800000000000008B, 0x8000000000008089,
      0x8000000000008003, 0x8000000000008002, 0x8000000000000080,
      0x000000000000800A, 0x800000008000000A, 0x8000000080008081,
      0x8000000000008080, 0x0000000080000001, 0x8000000080008008]
INDICES = [10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2,
           20, 14, 22, 9, 6, 1]
ROLS = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
        18, 39, 61, 20, 44]


BC = '  bc{i} = {xor};'
THETA = '''  t = bc{i1} ^ ((bc{i2} << 1) | (bc{i2} >> 63));
{xor}
'''
PI_RHO_TEMPLATE = '''\
  t1 = t2;
  t2 = a[{j}];
  a[{j}] = (t1 << {shl}) | (t1 >> {shr});\
'''

for r in range(24):
    for i in range(5):
        xor = ' ^ '.join('a[{}]'.format(j) for j in range(i, 25, 5))
        print(BC.format(i=i, xor=xor))

    i = 0
    for i1, i2 in [(4, 1), (0, 2), (1, 3), (2, 4), (3, 0)]:
        xor = '\n'.join('  a[{j}] ^= t;'.format(j=j) for j in range(i, 25, 5))
        print(THETA.format(i1=i1, i2=i2, xor=xor))
        i += 1

    print('  t2 = a[1];')
    for j, shl in zip(INDICES, ROLS):
        print(PI_RHO_TEMPLATE.format(j=j, shl=shl, shr=(64 - shl)))
        i = j

    for i in range(0, 25, 5):
        for j in range(i, i + 5):
            print('  bc{jmod} = a[{j}];'.format(jmod=j % 5, j=j))
        for j, (j1, j2) in zip(range(i, i + 5),
                               [(2, 1), (3, 2), (4, 3), (0, 4), (1, 0)]):
            print('  a[{j}] ^= bc{j1} & (~bc{j2});'.format(j=j, j1=j1, j2=j2))

    print('  a[0] ^= {:#018x}ULL;'.format(RC[r]))
