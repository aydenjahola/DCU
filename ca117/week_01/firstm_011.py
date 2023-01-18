#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()

for line in lines:
    tokens = line.strip().split()

    i = 0
    while i < len(tokens):
        if tokens[i].startswith("m"):
            tokens[i] = tokens[i].capitalize()
            break
        i += 1
    print(" ".join(tokens))
