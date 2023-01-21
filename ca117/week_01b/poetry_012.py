#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
max_len = max(len(line) for line in lines)

for line in lines:
    line = line.rstrip()
    spaces = " " * int((max_len - len(line)) / 2) + " "
    print(f"{spaces}{line}")

