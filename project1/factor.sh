#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# factor.sh
# finds the smallest factor of a number inputted as the argument

usage() {
    echo "usage: " $0 " requires the following argument"
    echo "-n|--number : number to find the smallest prime factor of"
    echo "[-h|--help] : display this message"

}
if [[ "$#" != 2 ]] || [[ "$1" = "-h" ]] || [[ "$1" = "--help" ]] || [[ "$1" != "-n" ]] || [[ "$1" != "--number" ]]; then
    usage
    exit 1
fi

# getting the number into the $1 slot
shift

lowestNumber = expr "$1" / 2
moddedNumer = $(("$1" % "$lowestNumber"))
while [[ "lowestNumber"%  ]]
do

done