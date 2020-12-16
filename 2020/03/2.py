import sys

slope = [row for row in sys.stdin]


def hits(right, down):
    down_slope = slope[::down]
    path = range(0, len(down_slope)*right, right)
    return sum(1 for r, c in zip(down_slope, path) if r[c % (len(r)-1)] == "#")


print(hits(1, 1)*hits(3, 1)*hits(5, 1)*hits(7, 1)*hits(1, 2))
