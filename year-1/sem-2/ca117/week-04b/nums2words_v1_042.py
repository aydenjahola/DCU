#!/usr/bin/env python3

import sys

num_to_word = {
    0: 'zero',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten'
}

for line in sys.stdin:
    numbers = list(map(int, line.strip().split()))
    words = [num_to_word[number] for number in numbers]
    print(' '.join(words))
