#!/usr/bin/env python3

import sys

vowels = 'aeiou'

def decode(words):
    for vowel in vowels:
        words = words.replace(f"{vowel}p{vowel}", vowel)
    return words

print(*map(decode, map(str.strip, sys.stdin)), sep='\n')

