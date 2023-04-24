#!/usr/bin/env python3

import sys

def count_magic_numbers(n):
    count = 0
    power = 1
    while power <= n:
        count += (n // power) // 10 * power
        remainder = (n // power) % 10
        if remainder == 3:
            count += n % power + 1
        elif remainder == 9:
            count += power
        elif remainder > 3:
            count += power
        power *= 10
    return count

def find_kth_magic_number(k, low, high):
    if low == high:
        return low

    mid = (low + high) // 2
    count = count_magic_numbers(mid)
    if count < k:
        return find_kth_magic_number(k, mid + 1, high)
    else:
        return find_kth_magic_number(k, low, mid)

k = int(sys.stdin.readline())

print(find_kth_magic_number(k, 1, 10**18))

