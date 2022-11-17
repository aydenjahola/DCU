#!/usr/bin/env python3

import os
files = os.listdir(".")         # Line A.
shebang = "#!/usr/bin/env python"

i = 0
while i < len(files):
    with open(files[i]) as f:
        f = f.readline()
    if files[i].split(".")[-1] == "py" and 0 < len(f) or 0 < len(f) and f[0:21] == shebang:
        print(files[i])
    i = i + 1
