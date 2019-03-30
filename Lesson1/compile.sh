#!/bin/bash

cfiles=$(ls -f *.c | wc -l)
declare -a array
array=($(basename -s .c $(ls -f *.c)))
for (( i = 0; i < $cfiles; i++ ))
do
	gcc -o ${array[i]} ${array[i]}.c
	if [ $? -eq 0 ]
	then
		echo ${array[i]} compile completed.
		chmod u+x ${array[i]}
	fi
done

