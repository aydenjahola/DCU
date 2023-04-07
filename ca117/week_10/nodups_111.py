#!/usr/bin/env python3

import sys
import string


seen = []
def nodups(words):
    for index, word in enumerate(words):
        word = word.lower().strip(string.punctuation)
        if word in seen:
            words[index] = '.'
        else:
            seen.append(word)
    return ' '.join(words)


for line in sys.stdin:
    words = line.strip().split()
    print(nodups(words))
