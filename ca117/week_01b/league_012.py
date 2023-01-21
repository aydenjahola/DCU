#!/usr/bin/env python3

import sys

league_table = []

for line in sys.stdin:
    league_table.append(line.strip().split())

print("POS CLUB P W D L GF GA GD PTS")

for team in league_table:
    print(f"{team[0].rjust(3)} {team[1].rjust(20)} {team[2].rjust(3)} {team[3].rjust(3)} {team[4].rjust(3)} {team[5].rjust(3)} {team[6].rjust(3)} {team[7].rjust(3)} {team[8].rjust(3)} {team[9].rjust(4)}")

