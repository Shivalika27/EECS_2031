#!/bin/sh

if [ $# -ne 2 ]
then
        echo "Error: needs two files"
        exit 1
fi

cat $1 |
while read key1 firstName lastName
do
	cat $2 |
	while read ID key2 avgMark
	do
		if [ "$key1" = "$key2" ] 
		then 
        		echo $lastName, $firstName $avgMark
		fi
	done
done
