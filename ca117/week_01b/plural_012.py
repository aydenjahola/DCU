#!/usr/bin/env python3

import sys

def pluralize(word):
    if word.endswith(('x', 's', 'z', 'o')) or word.endswith(('ch', 'sh')):
        return word + 'es'
    elif not any(c in 'aeiou' for c in word[-2:]) and word.endswith('y'):
        return word[:-1] + 'ies'
    elif word.endswith('f'):
        return word[:-1] + 'ves'
    elif word.endswith('fe'):
        return word[:-2] + 'ves'
    else:
        return word + 's'

for word in sys.stdin.readlines():
    print(pluralize(word.strip()))

