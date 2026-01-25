#!/bin/bash

# odd_numbers_range.sh - Prints odd numbers in a given range

echo "Enter starting range:"
read start

echo "Enter ending range:"
read end

echo "Odd numbers between $start and $end are:"

for (( i=start; i<=end; i++ ))
do
    if [ $((i % 2)) -ne 0 ]
    then
        echo $i
    fi
done
