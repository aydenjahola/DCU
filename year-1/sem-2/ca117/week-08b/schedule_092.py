#!/usr/bin/env python3

class Meeting(object):
    def __init__(self, hour, minute, duration):
        self.hour = hour
        self.minute = minute
        self.duration = duration

    def __str__(self):
        return f"{self.hour:02d}:{self.minute:02d} ({self.duration} minutes)"


class Schedule(object):
    def __init__(self):
        self.meetings = []

    def add(self, meeting):
        self.meetings.append(meeting)

    def __str__(self):
        sorted_meetings = sorted(self.meetings, key=lambda m: (m.hour, m.minute))
        lines = [str(m) for m in sorted_meetings]
        return "Schedule\n--------\n" + "\n".join(lines) + f"\nMeetings today: {len(self.meetings)}"
