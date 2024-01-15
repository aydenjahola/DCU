#!/usr/bin/env python3

class Patient(object):

    def __init__(self, name, age, doctor, medications=None):
        self.name = name
        self.age = age
        self.doctor = doctor
        self.medications = medications if medications is not None else []

    def add_medication(self, medication):
        if medication not in self.medications:
            self.medications.append(medication)

    def __str__(self):
        r = []
        r.append('Name: {}'.format(self.name))
        r.append('Age: {}'.format(self.age))
        r.append('Medications: {}'.format(', '.join(self.medications)))
        r.append('Doctor: {}'.format(self.doctor))
        return '\n'.join(r)
