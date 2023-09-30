#!/usr/bin/env python3

class MP3Track(object):

    def __init__(self, title, duration, artist):
        self.title = title
        self.duration = duration
        self.artist = artist

    def get_duration_string(self):
        minutes = self.duration // 60
        seconds = self.duration % 60
        return '{}:{:02d}'.format(minutes, seconds)

    def __str__(self):
        r = []
        r.append('Title: {}'.format(self.title))
        r.append('By: {}'.format(', '.join(self.artist)))
        r.append('Duration: {}'.format(self.get_duration_string()))
        return '\n'.join(r)


