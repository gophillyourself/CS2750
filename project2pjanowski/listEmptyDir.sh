#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# listEmptyDir.sh
# takes a name of a directory, displays all file names, adds the dir name to EmptyDir.txt

usage() {
  echo "usage: " $0 " requires an existing path to a directory or a directory in the relative path"
  echo "[-h|--help] : display this message"

}
if [[ "$#" != '1' ]] || [[ "$1" = "-h" ]] || { ! [[  -p "$1" ]] && ! [[ -d "$1" ]]; }; then
  usage
  exit 1
fi

ls -l $1 | sed -n 's/[^d].* //p'
