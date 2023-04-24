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
        for patient in self.d.values():
            if medication in patient.medications:
                result.append(patient)
        return result

    def get_least_common_meds(self):
        meds = {}
        for p in self.d.values():
            for med in p.medications:
                if med in meds:
                    meds[med] += 1
                else:
                    meds[med] = 1
        least_common_count = min(meds.values())
        least_common_meds = [med for med, count in meds.items() if count == least_common_count]
        return least_common_meds

    def get_most_common_meds(self):
        meds = {}
        for p in self.d.values():
            for med in p.medications:
                if med in meds:
                    meds[med] += 1
                else:
                    meds[med] = 1
        most_common_count = max(meds.values())
        most_common_meds = [med for med, count in meds.items() if count == most_common_count]
        return most_common_meds
