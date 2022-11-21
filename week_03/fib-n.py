#!/usr/bin/env python3

#Xn+2= Xn+1 + Xn

n = int(input())

num1 = 0
num2 = 1

i = 0
while i < n:
    print(num1)
    num3 = num1 + num2
    num1 = num2
    num2 = num3
    i = i + 1
