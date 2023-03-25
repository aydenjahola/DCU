#!/usr/bin/env python3

class Stack(object):

    def __init__(self):
        self.l = []

    def push(self, item):
        self.l.append(item)

    def pop(self):
        return self.l.pop()

    def top(self):
        return self.l[-1]

    def is_empty(self):
        return len(self.l) == 0

    def __len__(self):
        return len(self.l)


def matcher(s):
    stack = Stack()

    for c in s:
        if c in "({[":
            stack.push(c)
        elif c in ")}]":
            if stack.is_empty():
                return False
            top = stack.pop()
            if (top == "(" and c != ")") or (top == "{" and c != "}") or (top == "[" and c != "]"):
                return False

    return stack.is_empty()
