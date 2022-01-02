#!/bin/bash
g++ ./1.cpp -DONLINE_JUDGE -DLOCAL --std=c++17 -O2 -o fast || { echo 'fast comp failed'; break;}
g++ ./1_slow.cpp -DONLINE_JUDGE -DLOCAL --std=c++17 -O2 -o slow || { echo 'slow comp failed'; break;}
g++ ./gen.cpp --std=c++17 -O2 -o gen || { echo 'gen comp failed'; break;}

for((i=1;;i++)); do
    echo $i
#    ./gen $i > in
    ./fast < in > out1 || { echo 'fast run failed'; break;}
    ./slow < in > out2 || { echo 'slow run failed'; break;}
    diff -w out1 out2 || { break;}
done
