#!/usr/bin/env python3

import sys

def check_password_security(password):
    digit = 0
    lower = 0
    upper = 0
    special = 0

    for char in password:
        if char.isdigit():
            digit = 1
        elif char.islower():
            lower = 1
        elif char.isupper():
            upper = 1
        elif not (char.isalnum()):
            special = 1
    count = digit + lower + upper + special
    return count

for password in sys.stdin:
    password = password.strip()
    print(check_password_security(password))

