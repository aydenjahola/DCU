#!/usr/bin/env python3

n = int(input())
pos = 0
neg = 0

i = 0
while n != 0:
    if n > 0:
        pos = pos + n
    else:
        neg = neg + n
    n = int(input())
    i = i + 1

print(neg, pos)
