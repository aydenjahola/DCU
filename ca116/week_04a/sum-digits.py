#!/usr/bin/env python3

n = input()
x = len(n)
total = 0

i = 0
while i < x:
    total = total + int(n[i])
    i = i + 1

print(total)
