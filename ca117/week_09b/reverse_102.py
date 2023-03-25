#!/usr/bin/env python3

def reverse(lst):
    if len(lst) == 0:
        return []
    else:
        return [lst[-1]] + reverse(lst[:-1])
