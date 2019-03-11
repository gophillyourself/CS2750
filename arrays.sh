#!/usr/bin/env bash

input="yes"
count=0
declare -a reads
while read input && ! [[ -z $input ]]
do
  echo $count
  count=$((count+1))
  reads[count]=$input
  echo ${reads[*]}

done

echo done
