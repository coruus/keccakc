#!/usr/bin/env sh
size_max=$(echo "#include <stdint.h> \n size_max=SIZE_MAX" |
           cpp - |
           sed -En -e 's/size_max=([0-9]+)(.*)/\1/p' |
           tr -d ' ')
[ ${size_max} = '"18446744073709551615"' ] && echo "uint64_t" ||
[ ${size_max} = '"4294967295"' ] && echo "uint32_t" ||
echo "unknown: ${size_max}"
