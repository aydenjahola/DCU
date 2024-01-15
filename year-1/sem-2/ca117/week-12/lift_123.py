#!/usr/bin/env python3

import sys

f, s, g, u, d = map(int, input().split())

if s == g:
    print(0)
else:
    queue = [(s, 0)]
    visited = set()
    visited.add(s)

    while queue:
        curr_floor, num_pushes = queue.pop(0)

        if curr_floor + u <= f and curr_floor + u not in visited:
            if curr_floor + u == g:
                print(num_pushes + 1)
                break
            queue.append((curr_floor + u, num_pushes + 1))
            visited.add(curr_floor + u)

        if curr_floor - d >= 1 and curr_floor - d not in visited:
            if curr_floor - d == g:
                print(num_pushes + 1)
                break
            queue.append((curr_floor - d, num_pushes + 1))
            visited.add(curr_floor - d)

    else:
        print("Sorry Sheila!")
