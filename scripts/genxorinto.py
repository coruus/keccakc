"""Generates fully unrolled xorinto cases."""
from __future__ import division, print_function

CASE = """
  case {N}:
    {xors}
    break;"""
XOR = "    dest[{i}] ^= in[{i}];"
FIPS_STRENGTHS = [r * 2 for r in [128, 224, 256, 384, 512]]
RATES = [(1600 - strength) // 8 for strength in FIPS_STRENGTHS]

for rate in RATES:
    xors = "\n".join(XOR.format(i=i) for i in range(rate))
    print(CASE.format(N=rate, xors=xors))
