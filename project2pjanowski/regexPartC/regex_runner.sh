#!/bin/bash

regexFile='regex'

inputFile='input'

while read -r regex; do
	echo "---------------"
	echo "$regex"
	echo sed "$regex" "$inputFile"
	sed "$regex" "$inputFile"

done < "$regexFile"
