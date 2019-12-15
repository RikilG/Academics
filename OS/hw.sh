#!/bin/bash

gcc hw.c
./a.out $1
out=`./a.out $1`
rm a.out