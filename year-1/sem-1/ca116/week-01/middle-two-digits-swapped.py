#!/usr/bin/env python3

num = int(input())

div = num % 10000
div = div // 100

first = div // 10
second = div % 10

swapped = (second * 10) + first

print(swapped)
