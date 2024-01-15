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

    def __str__(self):
        sorted_customers = sorted(self.customers.values(), key=lambda x: x.number)
        details = [str(customer) for customer in sorted_customers]
        total_funds = sum([customer.balance for customer in self.customers.values()])
        return '\n'.join(details) + '\nTotal funds: {:.02f}'.format(total_funds)


from bank_v2_123 import Customer, Bank

def main():
    c1 = Customer('Alan Wren', 12434655, 100.00)
    c2 = Customer('John Squire', 54211677, 200.22)
    c3 = Customer('Ian Brown', 10145211, 1.50)

    b = Bank()

    b.add(c1)
    b.add(c2)
    b.add(c3)

    print(b)

if __name__ == '__main__':
    main()
