#!/usr/bin/env python3

import sys

capacity = int(input())
num_denied = 0
num_inside = 0

for line in sys.stdin:
    line = line.strip()
    if line.startswith('enter'):
        size = int(line.split()[1])
        if num_inside + size > capacity:
            num_denied += 1
        else:
            num_inside += size
    elif line.startswith('leave'):
        size = int(line.split()[1])
        num_inside -= size

print(num_denied)
