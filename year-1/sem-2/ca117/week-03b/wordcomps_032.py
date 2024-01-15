#!/usr/bin/env python3

import sys

def contains_all_vowels(word):
    vowels = set('aeiou')
    for char in word:
        if char.lower() in vowels:
            vowels.discard(char.lower())
        if not vowels:
            return True
    return False

def count_words_ending_in_iary(words):
    return len([word for word in words if word.lower().endswith('iary')])

def get_words_with_most_es(words):
    max_e_count = 0
    for word in words:
        e_count = word.lower().count('e')
        if e_count > max_e_count:
            max_e_count = e_count
    return [word for word in words if word.lower().count('e') == max_e_count]

words = [line.strip() for line in sys.stdin]

shortest_word_with_all_vowels = None
for word in words:
    if contains_all_vowels(word):
        if (not shortest_word_with_all_vowels) or (len(word) < len(shortest_word_with_all_vowels)):
            shortest_word_with_all_vowels = word

print("Shortest word containing all vowels:", shortest_word_with_all_vowels)
print("Words ending in iary:", count_words_ending_in_iary(words))
print("Words with most e's:", get_words_with_most_es(words))

