#!/usr/bin/env python3

n = input()

a = 0
b = 0

i = 0
while i < len(n):
    pos = int(n[len(n) - i - 1])
    decimal = pos * (2 ** a)
    a = a + 1
    i = i + 1
    b = b + decimal

print(b)
