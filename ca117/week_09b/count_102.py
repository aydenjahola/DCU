#!/usr/bin/env python3

def count(s):
    if s == '':
        return 0
    else:
        return 1 + count(s[1:])
