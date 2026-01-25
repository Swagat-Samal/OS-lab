#!/bin/bash

echo "Enter a number:"
read n
echo "Prime factors are:"
for (( i=2; i<=n; i++ ))
do
    if [ $((n % i)) -eq 0 ]
    then
        echo $i
        while [ $((n % i)) -eq 0 ]
        do
            n=$((n / i))
        done
    fi
done
