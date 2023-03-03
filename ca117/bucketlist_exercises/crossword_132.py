#!/usr/bin/env python3

import sys

# Read the input words from stdin
a, b = input().split()

# Find the shared letter and its index in each word
shared_letter = set(a) & set(b)
shared_letter_index_a = max([a.rfind(l) for l in shared_letter])
shared_letter_index_b = max([b.rfind(l) for l in shared_letter])

# Print the crossword grid
for i, c in enumerate(a):
    if i == shared_letter_index_a:
        print(b)
    else:
        print('.' * shared_letter_index_b + c + '.' * (len(b) - shared_letter_index_b - 1))
