#!/usr/bin/env bash

echo 1.
# any word that has a t, any vowel, then a k
sed -n '/t[aeiou].k/p' regex_test.txt

echo 2.
# matches any word that has a t in it
sed -n '/t*/p' regex_test.txt

# echo 3.
# sed '/^$/!d' #delete all none empty lines
# #^ start of a line
# #$ end of line
# #d delete the lines
# #! opposite

echo 3.
# matches on the word 'dog'
sed -n '/\<dog\>/p' regex_test.txt

echo 4.
#
sed -n '/\<[dD]o*g\>/p' regex_test.txt

echo numbers
sed -n 's/[0-9]/subbed/p' regex_test.txt

echo weird regex
reg1=[^,] #anything without a comma
reg2=.* #anything

# should swap thing on either side of a comma
sed -n 's/\([^,]*\),/ \(.*\)/' regex_test.txt

# deletes line that starts with table and ends with table tags
sed -n '/<table .*>/,/<\/table>/d' regex_test.txt

# adds a tab to each
sed 's/^/\t/p' regex_test.txt

sed '/^$/!s/^/\t/' regex_test.txt

# all dirs
ls -l | grep ^d | sed 's/^d.* //p'

ls -F | grep '/$' | sed 's/\/$//'
