#!/usr/bin/env python3

n = int(input())

#n_even = n // 2
#n_odd = 3 * n + 1

if n % 2 == 0:
    n = n // 2
    print(n)
else:
    n = n * 3 + 1
    print(n)
