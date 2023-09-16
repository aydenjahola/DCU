#!/usr/bin/env python3

import sys
import math

for cal in sys.stdin:
    calories = int(cal.strip())
    bars = math.ceil(calories / 400)

    print(bars)
