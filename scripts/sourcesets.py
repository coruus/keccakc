from __future__ import division, print_function

from os.path import splitext, join

class SourceSet(object):
    def __init__(self, name='', sources=None, prefix=''):
        if sources is None:
            sources = []
        self.prefix = prefix
        self._sources = sources
        self.name = name

    def __repr__(self):
        return ' '.join(self.sources)

    @property
    def sources(self):
        return ['{}'.format(join(self.prefix, source))
                for source in self._sources]

    def __add__(self, other):
        return SourceSet(prefix='', sources=self.sources + other.sources)

varopt64 = SourceSet(prefix='keccak/keccak/keccakp-1600',
                     sources=['keccakp-varopt64.c', 'keccakp-tiny64.c', 'keccakp-])
keccaks = {'varopt64': varopt64}
sponge = SourceSet(prefix='keccak/constructions/sponge',
                   sources=['sponge.c'])
sha3 = SourceSet(prefix='keccak/fips202/sha3',
                 sources=['sha3_224.c', 'sha3_256.c', 'sha3_384.c', 'sha3_512.c'])
shake = SourceSet(prefix='keccak/fips202/shake',
                  sources=['shake128.c', 'shake256.c'])
fips202 = sha3 + shake + sponge
tests = SourceSet(prefix='keccak/tests',
                  sources=['test-sha3.c', 'test0-sha3.c'])
for name, keccak in keccaks.iteritems():
    for test in tests.sources:
        exec_name = '{}-{}'.format(name, splitext(test)[0].split('/')[-1])
        print(exec_name + ': ' + test + ' ' + str(keccak + fips202))
