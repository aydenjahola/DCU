#!/usr/bin/env python3

import sys

inputs = sys.stdin.readlines()

for i in range(len(inputs)):
    n = int(inputs[i].strip())

    numbers = [x for x in range(1, n + 1)]

    modified_numbers = [x if x % 3 == 0 else 0 for x in numbers]
    print("Non-multiples of 3 replaced:", modified_numbers)
