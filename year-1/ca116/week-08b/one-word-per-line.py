#!/usr/bin/env python3

import sys

file = sys.stdin.read()
file = file.split()
file = "\n".join(file)

print(file)
