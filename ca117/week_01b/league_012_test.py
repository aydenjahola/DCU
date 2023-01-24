#!/usr/bin/env python3

line = '19 West Bromich Albion 11 1 3 7 8 23 -15 6\n'

tokens = line.split()
print(tokens)
# print(tokens[1:])
# print(tokens[1:3])
tt = tokens[1:-8]
teams = " ".join(tt)
print(teams)

