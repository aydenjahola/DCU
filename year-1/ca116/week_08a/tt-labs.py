#!/usr/bin/env python3

s = input()

while s != "end":
    tokens = s.split()
    length = int(tokens[2])
    if length > 1:
        print(" ".join(tokens))
    s = input()
