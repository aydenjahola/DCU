#!/usr/bin/env python3

import sys
import string

def get_word_frequencies(text):
    words = [word.strip(string.punctuation).lower() for line in text for word in line.split()]

    word_frequencies = {}
    for word in words:
        word_frequencies[word] = word_frequencies.get(word, 0) + 1

    return word_frequencies

def main():
    text = [line.strip() for line in sys.stdin]

    word_frequencies = get_word_frequencies(text)

    for word, frequency in sorted(word_frequencies.items()):
        print("{} : {}".format(word, frequency))

if __name__ == '__main__':
    main()
