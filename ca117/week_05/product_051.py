#!/usr/bin/env python3

import sys

x = sys.stdin.readline()
integer = int(x)

while integer > 9:

    product = 1
    for digit in str(integer):
        if digit != "0":
            product *= int(digit)
    # continuously changes
    integer = product
print(integer)
