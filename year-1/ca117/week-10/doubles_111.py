#!/usr/bin/env python3

import sys
import re

def count_double_vowels(word):
    return len(re.findall(r'(a{2}|e{2}|i{2}|o{2}|u{2})', word))

max_word = None
max_count = -1

for line in sys.stdin:
    word = line.strip()
    count = count_double_vowels(word)
    if count > max_count:
        max_count = count
        max_word = word

print(max_word)

