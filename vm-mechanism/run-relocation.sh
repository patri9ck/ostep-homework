#!/bin/bash

# Set the number of virtual addresses to generate for each run
NUM_ADDRESSES=1000

# Set the range of seeds to try (e.g., from 0 to 9 for variety)
SEED_START=0
SEED_END=9

# Define address space size
ASIZE="1k"

# Define physical memory size
PSIZE="4k"

# Run the Python script with varying limits
for seed in $(seq $SEED_START $SEED_END); do
  for limit in $(seq 0 256 1024); do
    # Run the script and capture the output
    result=$(./relocation.py -s $seed -a $ASIZE -p $PSIZE -n $NUM_ADDRESSES -l ${limit} -c)
    
    # Count occurrences of "VALID" and "SEGMENTATION VIOLATION" in the output
    valid_count=$(echo "$result" | grep -c "VALID")
    segfault_count=$(echo "$result" | grep -c "SEGMENTATION VIOLATION")

    # Calculate the fraction of valid addresses
    if [ $((valid_count + segfault_count)) -gt 0 ]; then
      fraction_valid=$(echo "scale=4; $valid_count / ($valid_count + $segfault_count)" | bc)
    else
      fraction_valid=0
    fi

    # Output the fraction of valid addresses for each limit value
    echo "Seed: $seed, Limit: $limit, Valid Fraction: $fraction_valid"
  done
done

