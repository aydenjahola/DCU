#!/usr/bin/env python3

import sys

x1, y1 = map(int, sys.stdin.readline().split())
x2, y2 = map(int, sys.stdin.readline().split())
x3, y3 = map(int, sys.stdin.readline().split())

x4 = x1 if x1 != x2 and x1 != x3 else x2 if x2 != x1 and x2 != x3 else x3
y4 = y1 if y1 != y2 and y1 != y3 else y2 if y2 != y1 and y2 != y3 else y3

print(x4, y4)
