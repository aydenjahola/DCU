#!/usr/bin/env python3

import sys

file = sys.stdin.readlines()

i = 0
while i < len(file):
    f = file[i].split("/")
    print(f[len(f) - 1].rstrip())
    i = i + 1
