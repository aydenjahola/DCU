#!/usr/bin/env python3

import sys
low = sys.stdin.readlines()

def qnou(s):
    s = s.replace("qu", "")
    return "q" in s

qnous = [word.strip() for word in low if qnou(word.lower())]

print("Words with q but no u:", qnous)
