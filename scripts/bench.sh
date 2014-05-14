#!/usr/bin/env sh
find build -name "bench-*" | sort | parallel -u -j1 "echo {} ; {}" | tee "perf/bench-$(scripts/isodate.sh)-@$(git rev-parse HEAD).txt"
