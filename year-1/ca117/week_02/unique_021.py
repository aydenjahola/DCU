#!/usr/bin/env python3

import string
import sys

unique_words = set()

for line in sys.stdin:
    line = line.translate(line.maketrans("", "", string.punctuation))
    line = line.lower()
    words = line.split()
    for word in words:
        if word.isalnum():
            unique_words.add(word)

print(len(unique_words))

