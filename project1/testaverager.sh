#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# factor.sh
# calculates the average of all tests given to it

usage() {
    echo "usage: " $0 " requires the following argument with the following stipulations"
    echo "First set of parameters should be your name, each part of you name should have a letter in it"
    echo "i.e. Mary Smith and 1234rfl ;liu8089 are both valid names"
    echo "The second set of numbers should be your test scores, the first pure number begins the second set"
    echo "Valid Usage Example: ./testaverager.sh Phillip Janowski 123 53 98 38 658 29"
    echo "[-h|--help] : display this message"
}

# initializing name string

# looping over all arguments until we find an arg that is only numbers
while [[ $1 =~ [a-z]|[A-Z] ]]
do
    name="$name $1"
    shift
done


# checking length of string array name just to make sure there is a name
if [[ ${#name[@]} = 0 ]]; then
    usage
    exit 1
fi

# for counting the number of tests that will be averaged
count=0
while [[ $# != 0 ]]
do
    if [[ $1 =~ [a-z]|[A-Z] ]]; then
        usage
        exit 1
    fi
    total=$(($total + $1))
    count=$(($count + 1))
    shift
done

# makes sure there are numbers to be averaged
if [[ $count = 0 ]]; then
    usage
    exit 1
fi

average=$(($total / $count))
echo Average "$average"

# checking average then displaying proper message 
if [[ $average -lt 70 ]]; then 
    echo Sorry "$name" but you will have to retake the class!
else 
    echo Congratulations "$name," you passed with an average of "$average"!
fi