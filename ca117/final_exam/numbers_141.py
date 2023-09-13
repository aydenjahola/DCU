#!/usr/bin/env python3

import sys

for line in sys.stdin:
    a, b, c = line.strip().split()
    a = int(a)
    b = int(b)
    c = int(c)

    if a + b == c or b + a == c or a - b == c or b - a == c or a * b == c or a / b == c or b / a == c:
        print("yes")
    else:
        print("no")
