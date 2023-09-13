#!/usr/bin/env python3

class Meeting(object):

    def __init__(self, mid, organiser, start, end, attendee=None):
        self.mid = mid
        self.organiser = organiser
        self.start = start
        self.end = end
        self.attendee = attendee if attendee is not None else []

    def add_attendee(self, s):
        self.attendee.append(s)

    def duration_seconds(self):
        start_hours, start_minutes = map(int, self.start.split(':'))
        end_hours, end_minutes = map(int, self.end.split(':'))
        start_seconds = start_hours * 60 * 60 + start_minutes * 60
        end_seconds = end_hours * 60 * 60 + end_minutes * 60
        return end_seconds - start_seconds

    def __str__(self):
        r = []
        r.append('ID: {}'.format(self.mid))
        r.append('Organised by: {}'.format(self.organiser))
        r.append(f'When: {self.start}-{self.end}')
        r.append('For: {}'.format(', '.join(self.attendee)))
        duration_seconds = self.duration_seconds()
        duration_minutes, duration_seconds = divmod(duration_seconds, 60)
        duration_hours, duration_minutes = divmod(duration_minutes, 60)
        r.append(f'Duration: {duration_hours:02d}:{duration_minutes:02d}:{duration_seconds:02d}')
        return '\n'.join(r)
