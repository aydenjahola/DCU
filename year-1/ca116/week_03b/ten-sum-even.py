#!/usr/bin/env python3

total = 0

i = 0
while i < 10:
    n = int(input())
    total = total + (n * ((n - 1) % 2))
    i = i + 1

print(total)
