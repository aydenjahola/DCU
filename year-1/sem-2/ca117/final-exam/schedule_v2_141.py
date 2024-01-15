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


    def __str__(self):
        r = []
        r.append('ID: {}'.format(self.mid))
        r.append('Organised by: {}'.format(self.organiser))
        r.append(f'When: {self.start}-{self.end}')
        r.append('For: {}'.format(', '.join(self.attendee)))
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

    def clash(self, attendee):
        clash_list = []
        for meeting in self.d.values():
            if attendee in meeting.attendee:
                clash_list.append(meeting)
        return clash_list


from schedule_v2_141 import Meeting, Schedule

def main():
    m1 = Meeting(1, 'Sue', '14:00', '15:00', ['Max'])
    m2 = Meeting(2, 'Ned', '09:10', '10:20', ['Zoe'])
    m3 = Meeting(3, 'Roy', '10:00', '14:00', ['Max', 'Zoe'])

    s = Schedule()

    s.add(m1)
    s.add(m2)
    s.add(m3)

    clash_list = s.clash()
    assert(len(clash_list) == 1)
    assert('Zoe' in clash_list)

if __name__ == '__main__':
    main()
