import sys

t = set(int(e) for e in sys.stdin)
r = next(e1*e2*(2020-e1-e2) for e1 in t for e2 in t if 2020-e1-e2 in t)
print(r)
