#!/usr/bin/env python3

home = int(input())
away = int(input())

if home > away:
    print("Home win.")
elif home == away:
    print("Draw.")
else:
    print("Away win.")
