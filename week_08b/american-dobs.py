#!/usr/bin/env python3

with open("irish-dobs.txt") as f:
    file = f.readlines()

with open("american-dobs.txt", "w") as f:
    i = 0
    while i < len(file):
        line = file[i].rstrip().split()
        dates = line[0].split("/")
        tmp = dates[0]
        dates[0] = dates[1]
        dates[1] = tmp
        dates = "/".join(dates)
        name = " ".join(line[1:])
        f.write(dates + " " + name + "\n")
        i = i + 1
