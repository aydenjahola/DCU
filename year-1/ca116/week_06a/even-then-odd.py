#!/usr/bin/env python3

odd = []

s = input()
while s != "end":
    n = int(s)
    if n % 2 == 0:
        print(n)
    else:
        odd.append(n)
    s = input()

i = 0
while i < len(odd):
    print(odd[i])
    i = i + 1
