#!/usr/bin/env python3

points = []
for _ in range(3):
    x, y = map(int, input().split())
    points.append((x, y))

x_coords = set()
y_coords = set()
for point in points:
    x_coords.add(point[0])
    y_coords.add(point[1])

missing_x = list(set(range(1, 1001)) - x_coords)[0]
missing_y = list(set(range(1, 1001)) - y_coords)[0]

print(missing_x, missing_y)

