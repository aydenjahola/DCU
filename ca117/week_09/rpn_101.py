#!/usr/bin/env python3

from math import sqrt

binops = {'+': float.__add__,
          '-': float.__sub__,
          '*': float.__mul__,
          '/': float.__truediv__}

uniops = {'n': float.__neg__,
          'r': sqrt}

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0

def calculator(line):
    stack = Stack()
    tokens = line.split()
    for token in tokens:
        if token in binops:
            try:
                arg2 = stack.pop()
                arg1 = stack.pop()
                result = binops[token](arg1, arg2)
                stack.push(result)
            except IndexError:
                raise IndexError('Invalid RPN expression')
        elif token in uniops:
            try:
                arg = stack.pop()
                result = uniops[token](arg)
                stack.push(result)
            except IndexError:
                raise IndexError('Invalid RPN expression')
        else:
            try:
                stack.push(float(token))
            except ValueError:
                raise IndexError('Invalid RPN expression')
    if len(stack.items) == 1:
        return stack.pop()
    else:
        raise IndexError('Invalid RPN expression')
