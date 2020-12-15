import sys

floor = 0

for c in sys.stdin.read().strip():
    floor = floor+1 if c == "(" else floor-1
print(floor)
