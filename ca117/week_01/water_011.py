#!/usr/bin/env python3

import sys

n = int(input())
buckets = list(map(int, input().split()))

filled_buckets = 0

for capacity in buckets:
    if n >= capacity:
        n -= capacity
        filled_buckets += 1
    else:
        break

print(filled_buckets)
