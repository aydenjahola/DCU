#!/usr/bin/env python3

def collatz(n):
    print(n)
    if n == 1:
        return
    elif n % 2 == 0:
        collatz(n // 2)
    else:
        collatz(n * 3 + 1)
