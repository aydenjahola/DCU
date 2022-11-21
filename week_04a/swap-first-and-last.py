#!/usr/bin/env python3

n = input()
x = len(n)

print(n[x - 1] + n[1:x - 1] + n[0])
