#!/usr/bin/env python3

import sys

for line in sys.stdin:
    x, y = map(int, line.strip().split())
    if x > 0:
        if y > 0:
            print("1")
        else:
            print("4")
    else:
        if y > 0:
            print("2")
        else:
            print("3")

