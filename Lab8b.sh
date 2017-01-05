#!/bin/sh

if [ $# -lt 2 ]
then
        echo "Error: needs two files"
        exit 1

elif [[ ! -f $1 || ! -f $2 || ! -r $1 || ! -r $2 || -d $1 || -d $2 ]]
then
        echo "There is a problem with one of the files"
        exit 1
fi

cat $1 |
while read key1 firstName lastName
do
	cat $2 |
	while read ID key2 mark1 mark2 mark3
	do
		if [ "$key1" = "$key2" ] 
		then
			if [ $# -eq 2 ]
			then 
				echo $lastName, $firstName $mark1 $mark2 $mark3
			fi

			sum=`expr $mark1 + $mark2 + $mark3`
                        average=`expr $sum / 3`
			
			if [ "$3" = "avg" ]
 			then
				echo $lastName, $firstName $average
			
			elif [ "$3" = "-F" ]
			then
				if [ $average -lt 50 ] 
				then
					echo $lastName, $firstName $mark1 $mark2 $mark3
				fi

			elif [[ $# -ne 2 && "$3" != "avg" && "$3" != "-F" ]]
			then
				echo "Error: avg of -F only please"
				break
			fi
		fi
	done
	if [[ $# -ne 2 && "$3" != "avg" && "$3" != "-F" ]]
        then
        	break
        fi  
done

