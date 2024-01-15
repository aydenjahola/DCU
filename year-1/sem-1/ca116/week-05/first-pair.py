#!/usr/bin/env python3

s = input()

i = 0
j = 1

while i < len(s) - 1 and (s[i] != s[j]):
    i = i + 1
    j = j + 1
if i < len(s) - 1:
    if s[i] == s[j]:
        print(s[i] + s[j])
