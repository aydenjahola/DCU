#!/usr/bin/env python3

class Lamp(object):

    def __init__(self, on=False):
        self.on = on

    def turn_on(self):
        if not self.on:
            self.on = True

    def turn_off(self):
        if self.on:
            self.on = False

    def toggle(self):
        self.on = not self.on
