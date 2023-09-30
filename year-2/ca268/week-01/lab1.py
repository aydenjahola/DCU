#!/usr/bin/env python3

# Q1

def q1_sum(self):

    total = 0

    for x in self:
        for n in x:
            if n % 2 == 0:
                total += n

    return total

#input_list = [
#        [1, 0, 2],
#        [5, 5, 7],
#        [9, 4, 3]
#]

#result = q1_sum(input_list)
#print(result)

# Q2

def move_vow(self):

    vowels = ""
    consonants = ""

    for char in self:
        if char in "aeiouAEIOU":
            vowels += char
        else:
            consonants += char

    result = vowels + consonants

    return result

#input_string = "This is DCU!"
#result = move_vow(input_string)
#print(result)

# Q3

class Memories:

    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def remember(self, x):
        if hasattr(self, x):
            return getattr(self, x)
        else:
            return False

#person1 = Memories(name='Tom', age='32', salary=50000)
#print(person1.remember('salary'))
#print(person1.remember('email'))

# Q4

class Test:

    def __init__(self, subject_name, correct_answers, passing_mark):
        self.subject_name = subject_name
        self.correct_answers = correct_answers
        self.passing_mark = passing_mark

class Student:

    def __init__(self, name):
        self.name = name

    def take_test(self, test, student_answers):
        count = sum(1 for ans in student_answers if ans in test.correct_answers)

        score = (count / len(test.correct_answers)) * 100

        if score >= float(test.passing_mark.strip("%")):
            print(f"{self.name} passed the {test.subject_name} test with the score {score:.1f}%")
        else:
            print(f"{self.name} failed the {test.subject_name} test!")

#paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
#paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
#paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

#stu1 = Student('Tom')
#stu1.take_test(paper2, ['1C', '2C', '3D', '4A'])

#stu2 = Student('John')
#stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B'])

# Q5

def histogram(num, char):
    for nums in num:
        line = char * nums
        print(line)

#histogram([6, 2, 15, 3, 20, 5], "=")

# Q6

def filter_star(choc, star_rating):
    result = {}

    for name, rating in choc.items():
        if len(rating) == star_rating:
            result[name] = rating

    if not result:
        return "No result found!"

    return result

#chocolates1 = {
#  'Luxury Chocolates': '*****',
#  'Tasty Chocolates': '****',
#  'Big Chocolates': '*****',
#  'Generic Chocolates': '***'
#}
#print(filter_star(chocolates1, 4))

#chocolates2 = {
#  'Luxury Chocolates': '*****',
#  'Tasty Chocolates': '****',
#  'Big Chocolates': '*****',
#  'Generic Chocolates': '***'
#}
#print(filter_star(chocolates2, 2))
