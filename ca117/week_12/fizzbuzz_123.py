#!/usr/bin/env python3

import sys

def fizzbuzz(x, y, n):
    for i in range(1, n+1):
        if i % x == 0 and i % y == 0:
            print("fizzbuzz")
        elif i % x == 0:
            print("fizz")
        elif i % y == 0:
            print("buzz")
        else:
            print(i)

if __name__ == "__main__":
    x, y, n = map(int, sys.stdin.readline().split())
    fizzbuzz(x, y, n)
