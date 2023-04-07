#!/usr/bin/env python3

import sys

left_side = []
for i, line in enumerate(sys.stdin):
    line = line.strip()
    if i % 2 == 0:
        print(line)
    else:
        left_side.insert(0, line)

for line in left_side:
    print(line)

