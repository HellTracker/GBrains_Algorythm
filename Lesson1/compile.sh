#!/bin/bash

echo Hello World!

cfiles=$(ls -f *.c | wc -l)
declare -a array
array=($(basename -s .c $(ls -f *.c)))
i=0
echo ${array[0]}
echo ${array[1]}
echo ${array[2]}
for (( i = 0; i < $cfiles; i++ ))
do
	#statements
	echo $i
	echo ${array[i]}
	gcc -o ${array[i]} ${array[i]}.c
	if [ $? -eq 0 ]
	then
		#statements
		echo ${array[i]} compile completed.
		chmod u+x ${array[i]}
	fi
done

