#!/usr/bin/env python3

class MP3Track(object):

    def __init__(self, title, duration, artist):
        self.title = title
        self.duration = duration
        self.artist = artist

    def __str__(self):
        r = []
        r.append('Title: {}'.format(self.title))
        r.append('By: {}'.format(', '.join(self.artist)))
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

    def __add__(self, other):
        result = MP3Collection()
        for track in self.tracks:
            result.add(track)
        for track in other.tracks:
            result.add(track)
        return result

