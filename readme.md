# Project description
This repository contains several implementations of common sorts.

# Implemented sorts
The following sorts are now implemented:
1. Bubble sort,
2. Insertion sort,
3. Quick sort.
4. Merge sort.

# Usage
To use one of them you should set variable for cmake. For example,
```bash
mkdir build && cd build
cmake -DQUICK=ON ../
```

After it you will turn on quick sort. You can turn on only one sort at the moment.
If you activate more than 1, program will be use the first mentioned sort from
[implemented](#implemented-sorts).

# Generate data
For generating random data you can use [generator from this repository](data_generator.c).
It creates `data.txt` file with required amount of random numbers.
