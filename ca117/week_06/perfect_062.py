#!/usr/bin/env python3

def get_divisors(n):
    divisors = []
    for i in range(1, n+1):
        if n % i == 0:
            divisors.append(i)
    return divisors

def get_proper_divisors(n):
    divisors = get_divisors(n)
    divisors.remove(n)
    return divisors

def is_perfect(n):
    proper_divisors = get_proper_divisors(n)
    return sum(proper_divisors) == n
