#!/usr/bin/env python3

month = int(input())
day = int(input())

InitMonth = 30 * (month - 1)
days = day - 1
DOTY = InitMonth + days

DOTW = DOTY % 7 + 1

print(DOTW)
