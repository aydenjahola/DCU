#!/usr/bin/env python3

import sys

start = sys.stdin.readline()

speeds = []
prevt, prevd = 0, 0

for line in sys.stdin:
    value = line.strip()
    value = line.split()
    d = int(value[1])
    t = int(value[0])

    speed = (d - prevd) / (t - prevt)
    speeds.append(speed)

    prevt, prevd = t, d

final = int(max(speeds))
print(final)
