#!/bin/bash

# print_digits.sh - Prints each digit of a number (in reverse order)

echo "Enter a number:"
read n

echo "Digits are:"
while [ $n -gt 0 ]
do
    digit=$((n % 10))
    echo $digit
    n=$((n / 10))
done
