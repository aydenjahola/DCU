#!/usr/bin/env python3

import sys

file = sys.argv[1:]
a = []

i = 0
while i < len(file):
    with open(file[i]) as f:
        curr = f.readline()
        while 0 < len(curr):
            j = 0
            num = curr.split()
            while j < len(num):
                a.append(num[j])
                j = j + 1
            curr = f.readline()
    i = i + 1

total = 0
i = 0
while i < len(a):
    total = total + int(a[i])
    i = i + 1

print(total)
