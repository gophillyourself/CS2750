#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# info.sh
# displays a bunch of stuff

#	“Usage” message (what should be typed to execute your file);
usage() {
    echo "usage: " $0 " requires the following arguments"
    echo "-p|--path : path to work with"
    echo "-f|--file : file to work with"
    echo "[-h|--help] : display this message"
}

# checking number of arguments or if the argument is for help, then exiting
if [[ "$#" != "4" ]] || [[ "$1" = "-h" ]] || [[ "$1" = "--help" ]]; then
    usage
    exit 1
fi

while [[ $# -gt 0 ]]
do
key="$1"
case $key in
    -p|--path)
        path="$2"
        shift # past argument
        shift # past value
        ;;
    -f|--file)
        file="$2"
        shift # past argument
        shift # past value
        ;;
    *)
        shift # past argument
        usage
        ;;
esac
done

#	The name of your script;
echo $0

#	Current date and time;
date
#	The name of the user;
whoami
#	The name of current working directory;
pwd
#	The name of UNIX machine;
hostname
#	The name of login shell;
echo $SHELL
if [ -f "$file" ]; then
    #	Contents of the required file;
    cat $file
    #	Number of text lines in the file;
    wc -l $file
else 
    echo "$file doesn't exist"
fi
#	Listing of the required directory;
ls $path
#	Total number of parameters of the script;
echo $#
#	Calendar for October of the current year;
cal -m 10
#	Disk usage;
df -h
#	Current number of users in the system;
w | wc -l
#	Current time.
date +%r