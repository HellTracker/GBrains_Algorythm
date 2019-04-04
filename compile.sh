#!/bin/bash

newfile=0
cfiles=$(ls -f *.c | wc -l)
declare -a array
array=($(basename -s .c $(ls -f *.c)))
for (( i = 0; i < $cfiles; i++ ))
do
	if [ -f ./bin/${array[i]}.md5 ]; then
		md5sum -c ./bin/${array[i]}.md5 --quiet --status
		if [ $? -eq 1 ]; then
			newfile=1
		fi
	else newfile=1
	fi
	if [[ $newfile == 1 ]]; then
		gcc -o ./bin/${array[i]} ${array[i]}.c -lm
		if [ $? -eq 0 ]; then
			echo ${array[i]} compile completed.
			md5sum ${array[i]}.c > ./bin/${array[i]}.md5
			chmod u+x ./bin/${array[i]}
		fi
	fi
done
