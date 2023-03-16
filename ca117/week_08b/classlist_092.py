#!/usr/bin/env python3

class Student(object):
    def __init__(self, name, id_num, modules):
        self.name = name
        self.id_num = id_num
        self.modules = sorted(modules)

    def average_mark(self):
        return round(sum(mark for _, mark in self.modules) / len(self.modules))

    def __str__(self):
        return f"Name: {self.name}\nID: {self.id_num}\nModules: {', '.join(module for module, _ in self.modules)}\nAverage mark: {self.average_mark()}"


class Classlist(object):
    def __init__(self):
        self.students = {}

    def add(self, student):
        self.students[student.id_num] = student

    def __str__(self):
        sorted_students = sorted(self.students.values(), key=lambda s: s.average_mark(), reverse=True)
        return "\n".join(str(student) for student in sorted_students)
