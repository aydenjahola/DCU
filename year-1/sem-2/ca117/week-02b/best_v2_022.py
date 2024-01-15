#!/usr/bin/env python3

import sys

try:
    with open(sys.argv[1]) as f:
        highest_mark = 0
        highest_mark_student = ""

        for line in f:
            try:
                elements = line.strip().split()
                mark = int(elements[0])
                student = ' '.join(elements[1:])
                if mark > highest_mark:
                    highest_mark = mark
                    highest_mark_student = student
            except ValueError:
                mark_value = elements[0]
                print(f"Invalid mark {mark_value} encountered. Exiting.")
                sys.exit()

    print("Best student:",highest_mark_student)
    print("Best mark:",highest_mark)

except FileNotFoundError:
    print(f"The file {sys.argv[1]} could not be opened.")
