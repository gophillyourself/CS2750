#!/bin/bash

regexFile='regex'

inputFile='input'

while read -r regex; do 
	echo "$regex"
	sed "$regex" "$inputFile"
done < "$regexFile"
