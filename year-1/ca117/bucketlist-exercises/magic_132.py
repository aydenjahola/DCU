#!/usr/bin/env python3

import sys

num = sys.stdin.readline().strip()

def magic_num(n):
    magic_num = ""
    while n > 0:
        if n % 2 == 0:
            magic_num += "9"
        else:
            magic_num += "3"
        n = (n - 1) // 2
    return int(magic_num[::-1])

n = int(num)
print(magic_num(n))
