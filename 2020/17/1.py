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
neighbours = [(x, y, z) for x, y, z in
              [(x, y, z) for x in nr for y in nr for z in nr
               if (x, y, z) != (0, 0, 0)]]

for x,  row in enumerate(initial):
    for y, col in enumerate(row):
        pocket[x][y][0] = col

for cycle in range(1, cycles + 1):
    new_pocket = copy.deepcopy(pocket)
    xr = range(-cycle, X + cycle)
    yr = range(-cycle, Y + cycle)
    zr = range(-cycle, Z + cycle)
    r = [(x, y, z) for x in xr for y in yr for z in zr]
    for x, y, z in r:
        count = sum(1 for nx, ny, nz in neighbours
                    if pocket[x+nx][y+ny][z+nz] == '#')
        new_pocket[x][y][z] = '#'\
            if count == 3 or (count == 2 and pocket[x][y][z] == '#')\
            else '.'
    pocket = new_pocket
    if cycle == cycles:
        print(sum(1 for x, y, z in r if pocket[x][y][z] == '#'))
