#!/usr/bin/env python3

import sys

animals = set()
common_animals = set()

common_animals.update(input().strip().split())

for line in sys.stdin:
    animal_set = set(line.strip().split())

    common_animals.intersection_update(animal_set)

sorted_animals = sorted(common_animals)

print(len(sorted_animals))
for animal in sorted_animals:
    print(animal)

