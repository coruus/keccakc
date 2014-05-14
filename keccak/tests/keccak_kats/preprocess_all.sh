#!/usr/bin/env sh
parallel './preprocess.sh < {} > {.}.recs' ::: *.txt
