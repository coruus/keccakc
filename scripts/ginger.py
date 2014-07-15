#!/usr/local/bin/python
"""A Python script to generate code with Jinja."""
from __future__ import print_function

import re
import sys

from yaml import load
from jinja2 import Template

BUILTIN_GLOBALS = eval('globals()', {}, {})
YAML_HEADER = re.compile(r'''/[*]yaml:\n(.*?)[*]/''', re.DOTALL)
PY_HEADER = re.compile(r'''/[*]py:\n(.*?)[*]/''', re.DOTALL)
CLEANUP = re.compile(r'''(/[*](py|yaml):\n.*?[*]/\n?)''', re.DOTALL)

def render(filename):
    """Render a Jinja2 template using an environment defined
       in a YAML or Python-based header.
    """
    with open(filename, 'rb') as f:
        s = f.read()
    env = {}
    yaml_match = YAML_HEADER.search(s)
    if yaml_match is not None:
        yamls = yaml_match.group(1)
        env.update(load(yamls))

    py_match = PY_HEADER.search(s)
    if py_match is not None:
        eval(compile(py_match.group(1), filename, 'exec'), env)
    for key in BUILTIN_GLOBALS:
        env.pop(key, None)
    s = CLEANUP.sub(r'', s)
    template = Template(s, block_start_string='/*%', block_end_string='*/',
                        variable_start_string='`', variable_end_string='`',
                        trim_blocks=True)
    print(template.render(env))

if __name__ == '__main__':
    render(sys.argv[1])
