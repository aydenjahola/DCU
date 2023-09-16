#!/usr/bin/env python3

import sys

for line in sys.stdin:
    line = line.strip()
    middle = len(line) // 2
    if len(line) % 2 == 1:
        print(line[middle])
    else:
        print("No middle character!")

