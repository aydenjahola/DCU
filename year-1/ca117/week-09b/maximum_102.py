#!/usr/bin/env python3

def maximum(lst):
    if len(lst) == 1:
        return lst[0]
    else:
        max_rest = maximum(lst[1:])
        return lst[0] if lst[0] > max_rest else max_rest
