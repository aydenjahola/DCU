#!/usr/bin/env python3

import sys

def is_anagram(word1, word2):
    return sorted(word1) == sorted(word2)

for line in sys.stdin:
    word1, word2 = line.strip().split()
    print(is_anagram(word1, word2))
