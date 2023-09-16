#!/usr/bin/env python3

s = input()

while s != "end":
    tokens = s.split()
    start = int(tokens[1])
    duration = int(tokens[2])
    end = (start + duration - 1) % 24
    start = str(start) + ":00"
    end = str(end) + ":50"
    print(tokens[0], start, end, " ".join(tokens[3:]))
    s = input()
