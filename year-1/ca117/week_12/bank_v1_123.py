#!/usr/bin/env python3

class Customer(object):

    def __init__(self, name, number, balance=0):
        self.name = name
        self.number = number
        self.balance = balance

    def __str__(self):
        r = []
        r.append('Name: {}'.format(self.name))
        r.append('Number: {}'.format(self.number))
        r.append('Balance: {:.02f}'.format(self.balance))
        return '\n'.join(r)

class Bank(object):
    def __init__(self):
        self.customers = {}

    def add(self, customer):
        self.customers[customer.number] = customer

    def remove(self, number):
        if number in self.customers:
            del self.customers[number]

    def lookup(self, number):
        if number in self.customers:
            return self.customers[number]
        return None
