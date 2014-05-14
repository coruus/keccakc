#!/usr/bin/env sh
find verification/compcert -name "*.trace" | parallel 'echo {} ; tail -1 {}'
