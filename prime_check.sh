#!/bin/bash

# prime_check.sh - Checks if a number is prime

echo "Enter a number:"
read n

flag=0

for (( i=2; i<=n/2; i++ ))
do
    if [ $((n % i)) -eq 0 ]
    then
        flag=1
        break
    fi
done

if [ $n -le 1 ]
then
    echo "$n is not a prime number"
elif [ $flag -eq 0 ]
then
    echo "$n is a prime number"
else
    echo "$n is not a prime number"
fi
