#!/usr/bin/env python3

import sys

a, b = input().strip().split()

x = None
x_idx_a = None
x_idx_b = None
for i in range(len(a)-1, -1, -1):
    if a[i] in b:
        x = a[i]
        x_idx_a = i
        x_idx_b = b.rindex(x)
        break

grid = [['.' for _ in range(len(b))] for _ in range(len(a))]
for i in range(len(a)):
    if i == x_idx_a:
        for j in range(len(b)):
            grid[i][j] = b[j]
    else:
        grid[i][x_idx_b] = a[i]

for row in grid:
    print(''.join(row))

