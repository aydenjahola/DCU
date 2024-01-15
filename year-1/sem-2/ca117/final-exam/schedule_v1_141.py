#!/usr/bin/env python3

class Meeting(object):

    def __init__(self, mid, organiser, start, end):
        self.mid = mid
        self.organiser = organiser
        self.start = start
        self.end = end

    def __str__(self):
        r = []
        r.append('ID: {}'.format(self.mid))
        r.append('Organised by: {}'.format(self.organiser))
        r.append(f'When: {self.start}-{self.end}')
        return '\n'.join(r)

class Schedule(object):
    
    def __init__(self):
        self.d = {}

    def add(self, s):
        self.d[s.mid] = s

    def remove(self, mid):
        del(self.d[mid])

    def lookup(self, mid):
        if mid in self.d:
            return self.d[mid]
        return None
