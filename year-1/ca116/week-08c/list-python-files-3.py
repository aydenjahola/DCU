#!/usr/bin/env python3

import os
files = os.listdir(".")         # Line A.
s = "#!/usr/bin/env python"

i = 0
while i < len(files):
    with open(files[i]) as f:
        f = f.readline()
        w = len(f)
    if files[i].split(".")[-1] == "py" and 0 < w or 0 < w and f[0:21] == s:
        print(files[i])
    i = i + 1
