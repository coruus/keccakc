from __future__ import division, print_function

CASE = '''\
      case {N}:
{}
        break;
'''
OP = '''        acc += (size_t)!(in1[{i}] == in2[{i}]);'''

#FIPS_LENS = [16, 24, 32, 48, 64, 512]
FIPS_LENS = [128]

for N in FIPS_LENS:
    print(CASE.format('\n'.join(OP.format(i=i) for i in range(N)), N=N))
