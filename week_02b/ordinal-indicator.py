#!/usr/bin/env python3

n = int(input())

number = n % 100

if number == 11 or number == 12 or number == 13:
    print("th")
elif number == 1 or n % 10 == 1:
    print("st")
elif number == 2 or n % 10 == 2:
    print("nd")
elif number == 3 or n % 10 == 3:
    print("rd")
else:
    print("th")
