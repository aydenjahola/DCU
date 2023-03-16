#!/usr/bin/env python3

class Contact(object):
    def __init__(self, name, phone, email):
        self.name = name
        self.phone = phone
        self.email = email

    def __str__(self):
        return f"{self.name} {self.phone} {self.email}"


class Contactlist(object):
    def __init__(self):
        self.d = {}

    def add(self, contact):
        self.d[contact.name] = contact

    def remove(self, name):
        if name in self.d:
            del self.d[name]

    def get(self, name):
        return self.d.get(name)

    def __str__(self):
        contact_list = []
        contact_list.append("Contact list")
        contact_list.append("------------")
        for name in sorted(self.d.keys()):
            contact_list.append(str(self.d[name]))
        return "\n".join(contact_list)
