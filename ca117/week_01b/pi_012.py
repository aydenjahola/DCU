#!/usr/bin/env python3

import math

while True:
    try:
        decimal_places = int(input())
        print(f"{math.pi:.{decimal_places}f}")
    except:
        break

