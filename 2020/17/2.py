import sys
import collections
import copy

initial = [row.strip() for row in sys.stdin]

cycles = 6
X = len(initial[0])
Y = len(initial)
Z = 1


def deep_dict():
    return collections.defaultdict(deep_dict)


pocket = deep_dict()
nr = range(-1, 2)
neighbours = [(x, y, z, w) for x, y, z, w in
              [(x, y, z, w) for x in nr for y in nr for z in nr for w in nr
               if (x, y, z, w) != (0, 0, 0, 0)]]

for x, row in enumerate(initial):
    for y, col in enumerate(row):
        pocket[x][y][0][0] = col

for cycle in range(1, cycles + 1):
    new_pocket = copy.deepcopy(pocket)
    xr = range(-cycle, X + cycle)
    yr = range(-cycle, Y + cycle)
    zr = range(-cycle, Z + cycle)
    wr = range(-cycle, Z + cycle)
    r = [(x, y, z, w) for x in xr for y in yr for z in zr for w in wr]
    for x, y, z, w in r:
        count = sum(1 for nx, ny, nz, nw in neighbours
                    if pocket[x+nx][y+ny][z+nz][w+nw] == '#')
        new_pocket[x][y][z][w] = '#'\
            if count == 3 or (count == 2 and pocket[x][y][z][w] == '#')\
            else '.'
    pocket = new_pocket
    if cycle == cycles:
        print(sum(1 for x, y, z, w in r if pocket[x][y][z][w] == '#'))
