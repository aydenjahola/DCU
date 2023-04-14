#!/usr/bin/env python3

import sys

def is_magic(n):
    while n > 0:
        digit = n % 10
        if digit != 3 and digit != 9:
            return False
        n //= 10
    return True

def generate_magic_numbers(k):
    count = 0
    n = 1
    while count < k:
        if is_magic(n):
            count += 1
        if count == k:
            return n
        n += 1
    return -1

def main():
    k = int(sys.stdin.readline().strip())
    magic_number = generate_magic_numbers(k)
    print(magic_number)

if __name__ == '__main__':
    main()

