#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# listEmptyDir.sh
# takes a name of a directory, displays all file names, adds the dir name to EmptyDir.txt

usage() {
  echo "usage: " $0 " requires an existing path to a directory or a directory in the relative path"
  echo "[-h|--help] : display this message"
}

checkDir() {
  directory=$1
  notEmpty=false
  # if anything exists in the current directory
  if [[ "$(ls -A $directory)" ]]; then
    echo Files in subdirectors of $1
    #  for every sub file or directory in the current direcotry
    for sub in $directory/*; do
      # if the current path is a file then output the name
      if [[ -f $sub ]]; then
        echo $sub
        # mark the file as not empty
        notEmpty=true
      # else call the checkDir function again
      else
        checkDir $sub
        # if the current path is empty put it at the bottom of empty dir
        if [[ "$notEmpty"=false ]]; then
          echo $sub >> EmptyDir.txt
        fi
      fi
    done
  fi
}

directory=$1

if [[ "$#" != '1' ]] || [[ "$directory" = "-h" ]] || { ! [[  -p "$directory" ]] && ! [[ -d "$directory" ]]; }; then
  usage
  exit 1
fi

# null out EmptyDir
truncate -s 0 EmptyDir.txt

checkDir $directory

# showing contents of EmptyDirs
echo Empty Subdirectors of $1
cat EmptyDir.txt
