#!/usr/bin/env python3

def magic_number(k):
    """
    Returns the k-th magic number
    """
    magic_num = 0
    base = 1
    while k > 0:
        base *= 10
        if k % 2 == 1:
            magic_num += base
        k //= 2
    return magic_num

if __name__ == "__main__":
    k = int(input())
    print(magic_number(k-1))
