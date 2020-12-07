import sys

groups = [g.strip().split('\n') for g in sys.stdin.read().split("\n\n")]
result = 0
for g in groups:
    sets = [set(c for c in p) for p in g]
    result = result + len(sets[0].intersection(*sets))
print(result)
