#!/bin/bash

echo "Number of args: $#"

echo #@

for i in $@; do
	echo $i
done

