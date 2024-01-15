#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
    if files[i].split(".")[-1] != "bak":
        s = files[i] + ".bak"
        with open(files[i]) as f_in:
                  file = f_in.read()
        with open(s, "w") as f_out:
                  f_out.write(file)
    i = i + 1
