#!/usr/bin/env python3

class BankAccount(object):

    def __init__(self, balance=0.0):
        self.balance = balance

    def deposit(self, value):
        self.balance += value

    def withdraw(self, value):
        if value <= self.balance:
            self.balance -= value

    def __str__(self):
        return f"Your current balance is {self.balance:.2f} euro"
