#!/usr/bin/env python3

import sys

def count_vowels(text):
    vowels = "aeiou"
    count = {v: 0 for v in vowels}
    for char in text:
        char = char.lower()
        if char in vowels:
            count[char] += 1
    return count

text = sys.stdin.read().strip()
vowel_counts = count_vowels(text)
width = len(str(max(vowel_counts.values())))
for vowel, count in sorted(vowel_counts.items(), key=lambda x: x[1], reverse=True):
    print(f"{vowel} : {count:{width}}")
