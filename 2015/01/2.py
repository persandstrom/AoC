import sys

floor = 0

for i, c in enumerate(sys.stdin.read().strip()):
    floor = floor+1 if c == "(" else floor-1
    if floor == -1:
        print(i+1)
        exit(0)
