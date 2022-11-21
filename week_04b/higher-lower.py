#!/usr/bin/env python3

prev = int(input())

i = 0
while i < 5:
    curr = int(input())
    if prev < curr:
        print("higher")
    elif prev == curr:
        print("equal")
    else:
        print("lower")
    prev = curr
    i = i + 1
