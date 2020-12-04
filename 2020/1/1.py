import sys

t = set(int(e) for e in sys.stdin)
r = next(e*(2020-e) for e in t if 2020-e in t)
print(r)
