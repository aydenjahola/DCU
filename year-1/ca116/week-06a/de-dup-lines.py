#!/usr/bin/env python3

a = []
s = ""

while s != "end":
    s = input()

    i = 0
    n = 0

    while i < len(a):
        if s != a[i]:
            i = i + 1
        elif s == a[i]:
            i = len(a)
            n = 1
        if n == 1 or s == "end":
            n = 0
        else: a.append(s)

i = set
while i < len(a):
    print(a[i])
    i = i + 1
