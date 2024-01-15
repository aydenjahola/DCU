#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()

for line in lines:
    line_1 = line.split("@")
    line_2 = line_1[0]
    line_3 = line_2.split(".")
    firstname = line_3[0]
    lastname = line_3[1]

    i = 0
    while i < len(lastname):
        if lastname[i].isdigit():
            lastname = str(lastname[0:i])
        i += 1

    print(firstname.title(), lastname.title())
