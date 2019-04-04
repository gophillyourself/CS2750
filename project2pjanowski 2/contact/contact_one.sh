#!/usr/bin/env bash
# Phillip Janowski
# CS2750
# contact_one.sh
# takes a regex and matches on contacts in the myContacts file

usage() {
  echo "usage: " $0 " requires a regular expression to match on contacts in the file myContacts"
  echo "regex must be a quoted string or warranty is voided"
  echo "[-h|--help] : display this message"
}

contacts=myContacts.txt

if [[ "$#" != '1' ]] || [[ "$regex" = "-h" ]]; then
  usage
  exit 1
fi

regex=$1
matched="false"
while read -r contact ; do

  if echo $contact | grep "$regex" ; then
    matched="true"
  fi
done < "$contacts"

if [[ "$matched" = "false" ]]; then
  echo No matches in "$contacts"
fi
