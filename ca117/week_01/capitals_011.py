#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()

for line in lines:
    line = line.strip()
    first_cap = line[0].capitalize()
    middle = line[1:-1]
    last_cap = line[len(line) - 1].capitalize()
    if len(line) > 1:
        print(first_cap + middle + last_cap)
