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
