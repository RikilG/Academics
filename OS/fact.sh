#!/bin/bash

gcc fact.c
./a.out $1
echo $?
rm a.out
