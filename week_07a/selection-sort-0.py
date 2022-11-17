#!/usr/bin/env python3

a = []
n = input()

while n != "end":
    a.append(int(n))
    n = input()

i = 0
smallest = a[i]
while i < len(a):
    if a[i] < smallest:
        smallest = a[i]
    i = i + 1

print(smallest)
