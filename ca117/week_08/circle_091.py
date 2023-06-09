#!/usr/bin/env python3

class Point(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def midpoint(self, other):
        x = (self.x + other.x) / 2
        y = (self.y + other.y) / 2
        return Point(x, y)

    def __str__(self):
        return f"({self.x:.1f}, {self.y:.1f})"


class Circle(object):
    def __init__(self, centre=None, radius=1):
        if centre is None:
            self.centre = Point()
        else:
            self.centre = centre
        self.radius = radius

    def __str__(self):
        return f"Centre: {self.centre}\nRadius: {self.radius}"
