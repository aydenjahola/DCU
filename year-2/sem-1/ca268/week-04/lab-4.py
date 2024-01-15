#!/usr/bin/env python3

# Q1

class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def reverse(self):
        self.items = self.items[::-1]

    def sort_using_recursion(self):
        if not self.is_empty():
            item = self.dequeue()
            self.sort_using_recursion()
            self.insert_sorted(item)

    def insert_sorted(self, item):
        if self.is_empty() or item > self.front():
            self.enqueue(item)
        else:
            temp = self.dequeue()
            self.insert_sorted(item)
            self.enqueue(temp)

    def front(self):
        return self.items[-1]

    def reverse_first_k_elements(self, k):
        if k <= 0 or k > self.size():
            return

        stack = []
        for _ in range(k):
            stack.append(self.dequeue())

        while stack:
            self.enqueue(stack.pop())

        for _ in range(self.size() - k):
            self.enqueue(self.dequeue())

if __name__ == '__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)

    print("Dequeue:", q.dequeue())
    print("Size:", q.size())

    print("Dequeue:", q.dequeue())
    print("Dequeue:", q.dequeue())

    print("Is Empty:", q.is_empty())
    print("Size:", q.size())

    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6)

    print("Queue:", q.items)

    q.reverse()
    print("Reversed Queue:", q.items)

    q.sort_using_recursion()
    print("Sorted Queue:", q.items)

    q.reverse_first_k_elements(2)
    print("Reversed First 2 Elements:", q.items)

# Q2

def generate_binary_sequence(n):

    result = []
    q = Queue()
    q.enqueue("1")  # Start with the binary representation of 1

     # Generate n binary numbers
    for _ in range(n):
        # Dequeue the front binary number and print it
        curr = q.dequeue()
        result.append(curr)

        # Enqueue the next two binary numbers
        q.enqueue(curr + '0')
        q.enqueue(curr + '1')

    return result


n = 16
binary_sequence = generate_binary_sequence(n)
print(' '.join(binary_sequence))

# Q3

class Stack:
    '''Python implementation of the stack'''

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

s = Stack()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        s.push(i)
    else:
        output.append(s.pop())

print('\n' + str(output))

# Q4

q = Queue()
output = []
str_input = 'EAS*Y*QUE***ST***IO*N***'
for i in str_input:
    if i not in '*':
        q.enqueue(i)
    else:
        output.append(q.dequeue())

print('\n' + str(output))

# Q5

def reverse(string_input):
    n = len(string_input)
    stack = Stack()

    for i in range(0, n, 1):
        stack.push(string_input[i])
    string_output = ""

    for i in range(0, n, 1):
        string_output += stack.pop()

    return string_output


str_input = "Hello DCU!"
str_output = reverse(str_input)
print("\nReversed string is: " + str_output)

# Q6

def evaluate_postfix(expression):
    stack = Stack()

    for char in expression:
        if char.isdigit():
            stack.push(int(char))
        else:
            operand2 = stack.pop()
            operand1 = stack.pop()

            if char == '+':
                result = operand1 + operand2
            elif char == '-':
                result = operand1 - operand2
            elif char == '*':
                result = operand1 * operand2
            elif char == '/':
                result = operand1 / operand2
            elif char == '^':
                result = operand1 ** operand2

            stack.push(result)

    return stack.pop()

postfix_expression = "1432^*+147--+"
result = evaluate_postfix(postfix_expression)
print(result)
