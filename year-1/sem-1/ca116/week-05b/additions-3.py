#!/usr/bin/env python3

i = 0
total = 0

while total != 1000:
    s = input()
    j = 0

    while j < len(s):
        if s[j] == "+":
            total = int(s[:j]) + int(s[j:])
            print(total)
        j += 1
