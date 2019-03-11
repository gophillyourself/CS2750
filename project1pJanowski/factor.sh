#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# factor.sh
# finds the smallest factor of a number inputted as the argument or tell if it is prime

usage() {
    echo "usage: " $0 " requires the following argument with the following stipulations"
    echo "-n|--number : number to find the smallest prime factor of, must be between 10 and 100"
    echo "[-h|--help] : display this message"

}

# checking for correct amount of args, for the help arg, and that the number arg is there
if [[ "$#" != 2 ]] || [[ "$1" = "-h" ]] || [[ "$1" = "--help" ]] || [[ "$1" != "-n" ]] && [[ "$1" != "--number" ]]; then
    usage
    exit 1
fi

# getting the number into the $1 slot
shift
#checking number is in the right range
if ! [[ $1 =~ ^[0-9]+$ ]] || [[ $1 -gt 100 ]] || [[ $1 -lt 10 ]]; then
    usage
    exit 1
fi

#initializing things for while loop
lowestNumber=$(($1 / 2))
currentNumber=${lowestNumber}
moddedNumber=$(($1 % $lowestNumber))
while [[ "$currentNumber" -gt 1 ]] 
do
    # checking for perfect divisibility for every number 
    moddedNumber=$(($1 % $currentNumber))
    if [[ ${moddedNumber} = 0 ]]; then
        lowestNumber=${currentNumber}
    fi
    currentNumber=$(( $currentNumber - 1 ))
done
# checking that the lowest number isn't the name as the one we calculated in the initialization
if [[ ${lowestNumber} = $(($1 / 2)) ]]; then
    echo "This number is prime"
else
    echo ${lowestNumber}
fi