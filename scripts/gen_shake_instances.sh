#!/usr/bin/env sh
p=keccak/fips202/shake
t=${p}/../shake.template.c
h=${p}/../shake.template.h
sed -e 's/SECURITY_STRENGTH/16/g;s/SHAKEFN/shake128/g;' ${t} > ${p}/shake128.c
sed -e 's/SECURITY_STRENGTH/32/g;s/SHAKEFN/shake256/g;' ${t} > ${p}/shake256.c
sed -e 's/SECURITY_STRENGTH/16/g;s/SHAKEFN/shake128/g;' ${h} > ${p}/shake128.h
sed -e 's/SECURITY_STRENGTH/32/g;s/SHAKEFN/shake256/g;' ${h} > ${p}/shake256.h
