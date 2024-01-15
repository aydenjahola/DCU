#!/usr/bin/env python3

n = int(input())

print("first:", n >= 70)
print("second:", n >= 50 and n < 70)
print("third:", n >= 40 and n < 50)
print("fail:", n < 40)
