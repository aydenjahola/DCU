#!/usr/bin/env python3

import sys
import math

def find_roots(a, b, c):
    discriminant = b ** 2 - 4 * a * c
    if discriminant < 0:
        return None
    else:
        root1 = (-b + math.sqrt(discriminant)) / (2 * a)
        root2 = (-b - math.sqrt(discriminant)) / (2 * a)
        return (root1, root2)

for line in sys.stdin:
    a, b, c = map(int, line.split())
    roots = find_roots(a, b, c)
    if roots is None:
        print("None")
    else:
        root1, root2 = sorted(roots)
        print("{:.1f}, {:.1f}".format(root1, root2))
