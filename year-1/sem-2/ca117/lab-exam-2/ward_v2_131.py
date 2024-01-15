#!/usr/bin/env python3

class Patient(object):
    def __init__(self, name, age, doctor, medications):
        self.name = name
        self.age = age
        self.doctor = doctor
        self.medications = medications

    def __str__(self):
        r = []
        r.append('Name: {}'.format(self.name))
        r.append('Age: {}'.format(self.age))
        r.append('medications: {}'.format(', '.join(self.medications)))
        r.append('Doctor: {}'.format(self.doctor))
        return '\n'.join(r)

class Ward(object):

    def __init__(self):
        self.d = {}

    def add(self, s):
        self.d[s.name] = s

    def remove(self, name):
        if name in self.d:
            del self.d[name]

    def lookup(self, name):
        return self.d.get(name, None)

    def get_patients_by_med(self, medication):
        result = []
        for p in self.d.values():
            if medication in p.medications:
                result.append(p)
        return result
