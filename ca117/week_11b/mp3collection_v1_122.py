#!/usr/bin/env python3

class MP3Track(object):

    def __init__(self, title, duration):
        self.title = title
        self.duration = duration

    def __str__(self):
        r = []
        r.append('Title: {}'.format(self.title))
        r.append('Duration: {}'.format(self.duration))
        return '\n'.join(r)

class MP3Collection:
    def __init__(self):
        self.tracks = []

    def add(self, track):
        if isinstance(track, MP3Track) and self.lookup(track.title) is None:
            self.tracks.append(track)

    def remove(self, title):
        for track in self.tracks:
            if track.title == title:
                self.tracks.remove(track)

    def lookup(self, title):
        for track in self.tracks:
            if track.title == title:
                return track
        return None
