#!/usr/bin/env python3

message = "Hello world.\n"
file_name = "hello.txt"

with open("hello.txt", "w") as f:
    f.write(message)
