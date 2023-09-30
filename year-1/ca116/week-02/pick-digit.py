#!/usr/bin/env python3

n = int(input())
p = int(input())

n = n // (10 ** p)
n = n % 10

print(n)
