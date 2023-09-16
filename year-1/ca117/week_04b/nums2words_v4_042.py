#!/usr/bin/env python3

def convert_to_words(num):
    if num < 20:
        return ONES[num]
    if num < 100:
        return TENS[num // 10] + ('' if num % 10 == 0 else '-' + ONES[num % 10])
    return "one hundred"

ONES = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
TENS = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

import sys

for line in sys.stdin:
    numbers = [int(num) for num in line.strip().split()]
    words = [convert_to_words(num) for num in numbers]
    print(" ".join(words))
