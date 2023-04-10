#!/usr/bin/env python3

class Triathlete(object):

    def __init__(self, name, tid):
        self.name = name
        self.tid = tid

    def __str__(self):
        r = []
        r.append('Name: {}'.format(self.name))
        r.append('ID: {}'.format(self.tid))
        return '\n'.join(r)

def sort_on(t):
    return t.name

class Triathlon(object):

    def __init__(self):
        self.d = {}

    def add(self, t):
        self.d[t.tid]= t

    def remove(self, tid):
        del(self.d[tid])

    def lookup(self, tid):
        if tid in self.d:
            return self.d[tid]
        return None

    def __str__(self):
        return '\n'.join(['{}'.format(t) for t in sorted(self.d.values(), key=sort_on)])
