#!/usr/bin/env python3

class Student(object):
    def __init__(self, name, id_num, modules):
        self.name = name
        self.id_num = id_num
        self.modules = sorted([module[0] for module in modules])
        self.marks = dict(modules)

    def average_mark(self):
        return round(sum(self.marks.values()) / len(self.marks))

    def __str__(self):
        modules_str = ", ".join(self.modules)
        return f"Name: {self.name}\nID: {self.id_num}\nModules: {modules_str}\nAverage mark: {self.average_mark()}"
