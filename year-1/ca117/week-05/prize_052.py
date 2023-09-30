#!/usr/bin/env python3

prize_position = int(input())
sequence = input()

swap_rules = {
    1: {"A": 2, "C": 3},
    2: {"A": 1, "B": 3},
    3: {"B": 2, "C": 1}
}

for swap in sequence:
    if swap in swap_rules[prize_position]:
        prize_position = swap_rules[prize_position][swap]

print(prize_position)
