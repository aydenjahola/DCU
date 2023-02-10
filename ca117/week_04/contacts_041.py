#!/usr/bin/env python3

import sys

def read_contacts(filename):
    contacts = {}
    with open(filename, 'r') as f:
        for line in f:
            name, number = line.strip().split()
            contacts[name] = number
    return contacts

def find_number(contacts, name):
    if name in contacts:
        return contacts[name]
    else:
        return "No such contact"

contacts = read_contacts(sys.argv[1])

for line in sys.stdin:
    name = line.strip()
    number = find_number(contacts, name)
    if number == "No such contact":
        print("Name:", name)
        print("No such contact")
    else:
        print("Name:", name)
        print("Phone:", number)
