#!/usr/bin/env python3

import sys

disq = []
results = {}

for line in sys.stdin:
    v = line.strip().split()
    name = " ".join(v[:-3])
    values = v[-3:]

    if all(score.isdigit() and int(score) > 0 for score in values):
        total = sum(int(score) for score in values)
        results[name] = total
    else:
        disq.append(name)

for name, total in sorted(results.items(), key=lambda x: x[1]):
    print(name + ":", total)

if len(disq) == 0:
    pass
elif len(disq) == 1:
    print("Disqualified:", "".join(disq))
else:
    print("Disqualified:", ", ".join(disq))
