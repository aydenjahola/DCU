#!/usr/bin/env python3

smallest = int(input())

i = 0
while i < 10 - 1:
    n = int(input())
    if n < smallest and n % 2 == 0:
        smallest = n
    i = i + 1

print(smallest)
