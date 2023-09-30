#!/usr/bin/env python3

import sys

for line in sys.stdin:
    numbers = line.strip().split()

    unique_numbers = [int(num) for num in numbers if numbers.count(num) == 1]

    if unique_numbers:
        print(max(unique_numbers))
    else:
        print("none")
