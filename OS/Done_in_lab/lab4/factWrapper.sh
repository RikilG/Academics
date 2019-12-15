#!/bin/bash

maxFact=1

while [ $maxFact -le 10 ]; do
	#echo "$maxFact:" `./fact.out $maxFact`
	./fact.out $maxFact
	echo $? # can store only one byte of info. so fact is return%256
	let maxFact=maxFact+1
done
