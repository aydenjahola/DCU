#!/usr/bin/env python3

n = int(input())
m = int(input())
x = m
print(x)

i = 1
while i < n:
    if x % 2 == 0:
        x = x // 2
        print(x)
    else:
        x = x * 3 + 1
        print(x)
    i = i + 1
