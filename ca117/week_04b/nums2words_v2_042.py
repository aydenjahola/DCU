#!/usr/bin/env python3

import sys

def map_num_to_word(num):
    if num >= 0 and num <= 10:
        return {
            0: "zero",
            1: "one",
            2: "two",
            3: "three",
            4: "four",
            5: "five",
            6: "six",
            7: "seven",
            8: "eight",
            9: "nine",
            10: "ten",
        }.get(num, "unknown")
    return "unknown"

def main():
    for line in sys.stdin:
        nums = list(map(int, line.strip().split()))
        words = list(map(map_num_to_word, nums))
        print(" ".join(words))

if __name__ == "__main__":
    main()
