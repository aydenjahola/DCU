#!/usr/bin/env python3

import os
files = os.listdir(".")         # Line A.

i = 0
while i < len(files):
    with open(files[i]) as f:
        f = f.read()
    if files[i].split(".")[-1] == "py" and 0 < len(f):       # Line B.
      print(files[i])
    i = i + 1
