#!/usr/bin/env python3

import sys

for line in sys.stdin:
    line = line.strip()
    num_e = len(line) - 2
    reply = 'h' + 'e' * (num_e * 2) + 'y'
    print(reply)
