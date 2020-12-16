import sys
t = [row for row in sys.stdin]
h = sum(1 for r, c in zip(t, range(3*len(t))[::3]) if r[c % (len(r)-1)] == "#")
print(h)
