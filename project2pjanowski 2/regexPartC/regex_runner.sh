#!/bin/bash
# Phillip Janowski
# CS2750
# regex_runner.sh
# runs the list of regexes in a file 'regex' against text in the file 'input' with sed
regexFile='regex'

inputFile='input'

while read -r regex; do
	if [[ $(echo "$regex" | sed '/^#/g') ]]; then
			echo "---------------"
			echo "$regex"
			echo sed "$regex" "$inputFile"
			sed "$regex" "$inputFile"
	fi


done < "$regexFile"
