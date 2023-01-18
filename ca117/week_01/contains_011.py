#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()

for line in lines:
    array = line.casefold().split(" ")
    arraySlice = array[0].strip()
    for s in array[1]:
        arraySlice = arraySlice.replace(s, "", 1)
    if len(arraySlice) > 0:
        print("False")
    else:
        print("True")
