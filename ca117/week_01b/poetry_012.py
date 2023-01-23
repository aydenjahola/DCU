#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
max_len = max(len(line) for line in lines)
max_len = max_len - 1

for line in lines:
    line = line.rstrip()
    print(f"{line:^{max_len}}")

