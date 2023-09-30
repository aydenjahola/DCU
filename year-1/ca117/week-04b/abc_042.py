#!/usr/bin/env python3

import sys

tokens = sys.stdin.readline().split()
numbers = [int(t) for t in tokens]
sort = sorted(numbers)

order = sys.stdin.readline().strip()
order = [t for t in order]
letter = sorted(order)

z = zip(letter, sort)

d = {k : v for k, v in z}

output = [str(d[let]) for let in order]
print(" ".join(output))
