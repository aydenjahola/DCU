#!/usr/bin/env python3

n = int(input())

total = ""

while n != 0:
    rem = n % 2
    n = n // 2
    total = str(rem) + total

print(total)
