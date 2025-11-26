#!/bin/bash

# Check if argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <number_of_random_numbers>"
    exit 1
fi

ARG=$(./random.sh $1)
../push_swap $ARG
