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

from mp3track_v2_122 import MP3Track

def main():
    t1 = MP3Track('Fools Gold', 604, ['The Stone Roses'])
    t2 = MP3Track('Shallow', 197, ['Lady Gaga', 'Bradley Cooper'])
    t3 = MP3Track('Telephone', 220, ['Beyonce', 'Lady Gaga'])

    print(t1)
    print(t2)
    print(t3)

if __name__ == '__main__':
    main()
