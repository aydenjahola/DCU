#!/usr/bin/env python3

import sys

def calculate(prices):
    return sum(prices)

def three_cakes(prices):
    total = 0
    for i, price in enumerate(sorted(prices, reverse=True), start=1):
        if i % 3 != 0:
            total += price
    return total

for line in sys.stdin:
    prices = list(map(int, line.strip().split()))
    if len(prices) > 2:
        print(three_cakes(prices))
    else:
        print(calculate(prices))
