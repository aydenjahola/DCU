#!/usr/bin/env python3

import sys

a, b, c = sorted([int(x) for x in input().split()])
order = input().strip()

numbers = {'A': a, 'B': b, 'C': c}

output = [numbers[x] for x in order]

print(" ".join(str(x) for x in output))
