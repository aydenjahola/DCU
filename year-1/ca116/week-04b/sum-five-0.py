#!/usr/bin/env python3

n = int(input())
total = 0

i = 0
while n != 0:
    total = total + n
    n = int(input())
    i = i + 1

print(total)
