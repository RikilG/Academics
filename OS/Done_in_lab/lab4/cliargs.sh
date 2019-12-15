#!/bin/bash

echo "Number of arguments passed is " $#
for i in $@; do
	echo $i
done
