#!/usr/bin/env python3

import calendar

poem = {0: "Monday",
        1: "Tuesday",
        2: "Wednesday",
        3: "Thursday",
        4: "Friday",
        5: "Saturday",
        6: "Sunday"}

poem_text = {0: "Monday's child is fair of face.",
        1: "Tuesday's child is full of grace.",
        2: "Wednesday's child is full of woe.",
        3: "Thursday's child has far to go.",
        4: "Friday's child is loving and giving.",
        5: "Saturday's child works hard for a living.",
        6: "Sunday's child is fair and wise and good in every way."}

try:
    while True:
        line = input()
        day, month, year = map(int, line.split())
        day_of_week = calendar.weekday(year, month, day)
        print("You were born on a",poem[day_of_week], "and", poem_text[day_of_week])
except EOFError:
    pass

