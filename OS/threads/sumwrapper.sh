#!/bin/bash

i=1
a=0
space=' '
while [[ $i -le $1 ]]; do
    a="$a $i"
    let i=i+1
done

echo Plain Sum
gcc plainsum.c
out=`time ./a.out $a`
echo $out
rm a.out

echo
echo Thread Sum
gcc -pthread threadsum.c
out=`time ./a.out $a`
echo $out
rm a.out