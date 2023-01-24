#!/usr/bin/env python3

import sys

league_table = []

lines = sys.stdin.readlines()

for line in lines:
    league_table.append(line.strip().split())

print(league_table)
