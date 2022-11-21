#!/usr/bin/env python3

num = int(input())

a = num // 100
b = (num // 10) - (a * 10)
c = (num) - ((num // 10) * 10)

print(a)
print(b)
print(c)
