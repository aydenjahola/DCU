#!/usr/bin/env python3

import sys

for line in sys.stdin:
    squashed_line = ''
    current_char = None
    current_count = 0
    for char in line.strip():
        if char == current_char:
            current_count += 1
        else:
            if current_char is not None:
                squashed_line += str(current_count) + current_char
            current_char = char
            current_count = 1
    squashed_line += str(current_count) + current_char
    print(squashed_line)
