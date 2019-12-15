#!/bin/bash

a=7

if [ $((a%2)) = 0 ]; then
	echo even
else 
	echo odd
fi
