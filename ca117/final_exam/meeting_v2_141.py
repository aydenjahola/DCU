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


from meeting_v2_141 import Meeting

def main():
    m1 = Meeting(1, 'Sue', '14:00', '15:00', ['Max'])
    m2 = Meeting(2, 'Ned', '09:10', '10:20')

    print(m1)
    print(m2)

    m1.add_attendee('Moe')
    print(m1)

    m2.add_attendee('Zoe')
    print(m2)

if __name__ == '__main__':
    main()
