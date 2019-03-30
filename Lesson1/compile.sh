#!/bin/bash

newfile=0
cfiles=$(ls -f *.c | wc -l)
declare -a array
array=($(basename -s .c $(ls -f *.c)))
for (( i = 0; i < $cfiles; i++ ))
do
	echo $i проход
	if [ -f ./bin/${array[i]}.md5 ]; then
		md5sum -c ./bin/${array[i]}.md5
		if [ $? -eq 1 ]; then
			newfile=1
		fi
	else newfile=1
	fi
	if [[ $newfile == 1 ]]; then
		md5sum ${array[i]}.c > ./bin/${array[i]}.md5
		gcc -o ./bin/${array[i]} ${array[i]}.c
		if [ $? -eq 0 ]; then
			echo ${array[i]} compile completed.
			chmod u+x ./bin/${array[i]}
		fi
	fi
done

