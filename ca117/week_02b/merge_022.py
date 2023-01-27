#!/usr/bin/env python3

import sys

def merge_files(file_1, file_2):
    with open(file_1) as f1, open(file_2) as f2:
        lines_1 = f1.readlines()
        lines_2 = f2.readlines()
        for i in range(len(lines_1)):
            print(lines_1[i].strip())
            print(lines_2[i].strip())

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("please use file_1 file_2 format")
    else:
        merge_files(sys.argv[1], sys.argv[2])

