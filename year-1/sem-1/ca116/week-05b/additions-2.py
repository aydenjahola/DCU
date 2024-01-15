#!/usr/bin/env python3

s = input()

i = 0
last = 0
total = 0
j = 0

while i < len(s):
    if s[i] == "+":
        total += int(s[last:i])
        last = i
    i += 1

while j == 0:
    print(total + int(s[last:]))
    j += 1
