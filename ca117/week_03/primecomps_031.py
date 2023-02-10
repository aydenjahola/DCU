#!/usr/bin/env python3

import sys

inputs = sys.stdin.readlines()

for i in range(len(inputs)):
    n = int(inputs[i].strip())

    numbers = [x for x in range(2, n + 1)]

    primes = [x for x in numbers if all(x % y != 0 for y in range(2, int(x ** 0.5) + 1))]
    print("Primes:", primes)
