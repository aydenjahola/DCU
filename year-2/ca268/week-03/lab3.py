#!/usr/bin/env python3

# Q1

def sum_q1(n):
    if n == 0:
        return 0
    else:
        return n + sum_q1(n - 1)

# usage:
result = sum_q1(6)
print(result)  # Output: 21


# Q2

def reverse_integer(n):
    if n < 10:
        return n
    else:
        last_digit = n % 10
        remaining_digits = n // 10
        reversed_result = reverse_integer(remaining_digits)
        return int(str(last_digit) + str(reversed_result))

# usage:
input_num = 123
reversed_num = reverse_integer(input_num)
print(reversed_num)  # Output: 321


# Q3

def reverse_string(s):
    if len(s) <= 1:
        return s
    else:
        last_char = s[-1]
        remaining_chars = s[:-1]
        reversed_result = reverse_string(remaining_chars)
        return last_char + reversed_result

# usage:
input_str = "hello"
reversed_str = reverse_string(input_str)
print(reversed_str)  # Output: "olleh"


# Q4

def reverse_list(numbers):
    if len(numbers) <= 1:
        return numbers
    else:
        last_element = numbers[-1]
        remaining_elements = numbers[:-1]
        reversed_result = reverse_list(remaining_elements)
        return [last_element] + reversed_result

# usage:
input_list = [1, 2, 3, 4]
reversed_list = reverse_list(input_list)
print(reversed_list)  # Output: [4, 3, 2, 1]


# Q5

def multiply(a, b):
    if b == 0:
        return 0
    elif b < 0:
        return -multiply(a, -b)
    else:
        return a + multiply(a, b - 1)

# usage:
result1 = multiply(10, 2)
print(result1)  # Output: 20

result2 = multiply(-51, -4)
print(result2)  # Output: 204

result3 = multiply(3, 9)
print(result3)  # Output: 27


# Q6

def is_heteromecic(number):
    for n in range(number + 1):
        if n * (n + 1) == number:
            return True
    return False

# usage:
result1 = is_heteromecic(110)
print(result1)  # Output: True

result2 = is_heteromecic(12)
print(result2)  # Output: True (as 3 * 4 = 12)

result3 = is_heteromecic(7)
print(result3)  # Output: False (no consecutive integers multiplication gives 7)


# Q7

def strlen(s):
    if s == "":
        return 0
    else:
        return 1 + strlen(s[1:])

# usage:
input_str = "Hello, World!"
length = strlen(input_str)
print(length)  # Output: 13 (length of the string "Hello, World!")

