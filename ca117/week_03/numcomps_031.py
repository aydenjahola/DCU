#!/usr/bin/env python3

import sys

inputs = sys.stdin.readlines()

for i in range(len(inputs)):
    n = int(inputs[i].strip())

    multiples_of_3 = []
    for x in range(1, n + 1):
        if x % 3 == 0:
            multiples_of_3.append(x)
    print("Multiples of 3:", multiples_of_3)

    squared_multiples_of_3 = []
    for x in multiples_of_3:
        squared_multiples_of_3.append(x**2)
    print("Multiples of 3 squared:", squared_multiples_of_3)

    double_multiples_of_4 = []
    for x in range(1, n + 1):
        if x % 4 == 0:
            double_multiples_of_4.append(2 * x)
    print("Multiples of 4 doubled:", double_multiples_of_4)

    multiples_of_3_or_4 = []
    for x in range(1, n + 1):
        if x % 3 == 0 or x % 4 == 0:
            multiples_of_3_or_4.append(x)
    print("Multiples of 3 or 4:", multiples_of_3_or_4)

    multiples_of_3_and_4 = []
    for x in range(1, n + 1):
        if x % 3 == 0 and x % 4 == 0:
            multiples_of_3_and_4.append(x)
    print("Multiples of 3 and 4:", multiples_of_3_and_4)
