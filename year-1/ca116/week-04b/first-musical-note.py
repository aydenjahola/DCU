#!/usr/bin/env python3

s = input()
notes = "abcdefg"
first_note = ""

i = 0
while i < len(s):
    n = 0
    while n < len(notes):
        if s[i] == notes[n]:
            first_note = s[i]
            print(first_note)
            n = len(notes)
            i = len(s)
        n = n + 1
    i = i + 1
