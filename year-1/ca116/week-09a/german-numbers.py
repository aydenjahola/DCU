#!/usr/bin/env python3

import sys

english = "one two three four five six seven eight nine ten"
german = "eins zwei drei vier funf sechs sieben acht neun zehn"

english = english.split()
german = german.split()

translation = {}

i = 0
while i < len(english):
    translation[english[i]] = german[i]
    i = i + 1

word = sys.stdin.readline().rstrip()

while 0 < len(word):
    if word in english:
        print(translation[word])
    word = sys.stdin.readline().rstrip()
