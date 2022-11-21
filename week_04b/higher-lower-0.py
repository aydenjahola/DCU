#!/usr/bin/env python3

prev = int(input())

i = 0
while prev != 0:
    curr = int(input())
    if prev < curr and curr != 0:
        print("higher")
    elif curr == prev and curr != 0:
        print("equal")
    elif prev > curr and curr != 0:
        print("lower")
    prev = curr
    i = i + 1
