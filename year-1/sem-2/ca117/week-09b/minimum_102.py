#!/usr/bin/env python3

def minimum(lst):
    if len(lst) == 1:
        return lst[0]
    else:
        min_rest = minimum(lst[1:])
        return lst[0] if lst[0] < min_rest else min_rest
