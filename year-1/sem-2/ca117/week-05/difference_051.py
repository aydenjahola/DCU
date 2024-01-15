#!/usr/bin/env python3

import sys

lines = sys.stdin.read().split()

first = lines[0]
second = lines[1]

i = 0
while i < len(first):

    j = 0
    dif = ""
    while j < len(first) and len(second):
        if first[j] == second[j]:
            dif += "-"
        if first[j] != second[j]:
            dif += "*"
        j += 1

    i += 1

print(first)
print(second)
print(dif)
