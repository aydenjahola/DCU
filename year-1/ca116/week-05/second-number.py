#!/usr/bin/env python3

s = input()

i = 0
while i < len(s) and (s[i] < "0" or "9" < s[i]):
    i = i + 1
if i < len(s):
    j = i
    while j < len(s) and (s[j] >= "0" or "9" <= s[j]):
        j = j + 1
        tmp = j
        while tmp < len(s) and (s[tmp] < "0" or "9" < s[tmp]):
            tmp = tmp + 1
        if i < len(s):
            b = tmp
            while b < len(s) and (s[b] >= "0" or "9" < s[b]):
                b = b + 1
print (s[tmp:b], tmp)
