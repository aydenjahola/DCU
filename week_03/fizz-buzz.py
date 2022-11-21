#!/usr/bin/env python3

n = int(input())

i = 0
while i < n:
    m = i + 1
    if m % 3 == 0 and m % 5 == 0:
        print("fizz-buzz")
    elif m % 3 == 0:
        print("fizz")
    elif m % 5 == 0:
        print("buzz")
    else:
        print(m)
    i = i + 1
