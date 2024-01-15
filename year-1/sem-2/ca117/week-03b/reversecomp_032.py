#!/usr/bin/env python3

import sys

words = [line.strip() for line in sys.stdin]

def binary_search(arr, word):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid].lower() == word:
            return True
        elif arr[mid].lower() < word:
            left = mid + 1
        else:
            right = mid - 1
    return False

result = []
for word in words:
    if len(word) < 5:
        continue
    reversed_word = word[::-1].lower()
    if binary_search(words, reversed_word):
        result.append(word)

print(result)
