#!/usr/bin/env python3

n = int(input())
hex = ""
strings = "0123456789abcdef"

i = 0
while n != 0:
    r = strings[n % 16]
    n = n // 16
    hex = r + hex
    i = i + 1

print(hex)
