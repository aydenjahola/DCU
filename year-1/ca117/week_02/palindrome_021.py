#!/usr/bin/env python3

import sys

for line in sys.stdin:
    line = line.strip()
    line = ''.join([i for i in line if i.isalnum()])
    line = line.lower()
    if line == line[::-1]:
        print("True")
    else:
        print("False")

