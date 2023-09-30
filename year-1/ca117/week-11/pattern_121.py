#!/usr/bin/env python3

import sys
from re import findall

pattern = sys.stdin.readline().strip()
words = []
for line in sys.stdin.readlines():
    words.append(line.strip())

#print(pattern)
#print(words)
# "\b" Match a word boundary, r = raw string
# \w =
# transform supplied pattern into regex
pattern = r"\b" + pattern.replace("-", r"\w",) + r"\b"
#print(pattern)

text = " ".join(words)
matches = findall(pattern, text)
if len(matches) > 0:
    print(", ".join(matches))
