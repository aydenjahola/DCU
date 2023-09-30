#!/usr/bin/env python3

import sys

typed = sys.stdin.readline().strip()
displayed = sys.stdin.readline().strip()

sticky = set()
i, j = 0, 0
while i < len(typed) and j < len(displayed):
    if typed[i] != displayed[j]:
        j += 1
    else:
        i += 1
        j += 1
    if j < len(displayed) and displayed[j] == typed[i-1]:
        sticky.add(typed[i-1])

print(''.join(sorted(sticky)))

