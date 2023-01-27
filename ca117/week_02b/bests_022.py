#!/usr/bin/env python3

import sys

try:
    with open(sys.argv[1]) as f:
        highest_mark = 0
        highest_mark_students = []

        for line in f:
            try:
                elements = line.strip().split()
                mark = int(elements[0])
                student = ' '.join(elements[1:])
                if mark > highest_mark:
                    highest_mark = mark
                    highest_mark_students = [student]
                elif mark == highest_mark:
                    highest_mark_students.append(student)
            except ValueError:
                mark_value = elements[0]
                print(f"Error: {mark_value} is not an integer.")

    if highest_mark_students:
        print("Best student(s):",", ".join(highest_mark_students))
        print("Best mark:",highest_mark)

except FileNotFoundError:
    print(f"The file {sys.argv[1]} could not be opened.")

