#!/usr/bin/env python3

total = 0
s = input()

while s != "end":
    tokens = s.split()
    day = int(tokens[2])
    total = total + day
    s = input()

print(total)
