#!/usr/bin/env python3

import sys

pangram = "abcdefghijklmnopqrstuvwxyz"

for line in sys.stdin:
    line = line.lower()
    missing = set(pangram) - set(line)
    if not missing:
        print("pangram")
    else:
        print("missing", "".join(sorted(missing)))
