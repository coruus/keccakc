#!/usr/bin/env sh
(echo "llvm revision";
 /usr/bin/env echo -n "llvm@" ; (cd ~/llvm35/llvm ; git rev-parse HEAD);
 echo "--------------------";
 echo "clang version"; clang -v ; echo "--------------------";
 echo "gcc version" ; gcc-4.9 -v ; echo "--------------------";
 echo "ccomp version" ; ccomp -help | head -1 ;  echo "--------------------";
 echo "frama-c version" ; frama-c -version ; echo "--------------------";
 echo "valgrind version" ; valgrind --version ;  echo "--------------------";
 ) > tool_versions_$(cat .machine_name).txt 2>&1
