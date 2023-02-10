#!/usr/bin/env python3

import sys

def read_contacts(filename):
    contacts = {}
    with open(filename, 'r') as f:
        for line in f:
            name, number, email = line.strip().split()
            contacts[name] = (number, email)
    return contacts

def find_contact(contacts, name):
    if name in contacts:
        return contacts[name]
    else:
        return None

contacts = read_contacts(sys.argv[1])

for line in sys.stdin:
    name = line.strip()
    contact = find_contact(contacts, name)
    if contact is None:
        print("Name:", name)
        print("No such contact")
    else:
        print("Name:", name)
        print("Phone:", contact[0])
        print("Email:", contact[1])
