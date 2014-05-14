#!/usr/bin/env bash
gsed=$(which gsed || echo -n sed)
${gsed} -re 's/#.*\n//' - | tr -s '\n' | tail -n +2
