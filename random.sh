#!/bin/bash

# Check if argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <number_of_unique_numbers>"
    exit 1
fi

n=$1

# Validate that n is a positive integer
if ! [[ "$n" =~ ^[0-9]+$ ]] || [ "$n" -le 0 ]; then
    echo "Error: Please provide a positive integer"
    exit 1
fi

# Generate n unique random numbers
shuf -i 1-65536 -n "$n"
