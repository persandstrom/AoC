import sys

input = [row.strip()for row in sys.stdin]
width = len(input[0])
heightmap = [int(i) for i in ''.join(input)]
basins = []

def add_to_basin(i):
    if heightmap[i] == 9:
        return
    new_basin = set([i])
    for basin in basins:
        if ((i - width >= 0 and i-width in basin) or
           ((i-1)%width < i%width and i-1 in basin) or
           ((i+1)%width > i%width  and i+1 in basin) or
           (i + width < len(heightmap) and i+width in basin)):
            new_basin = set.union(new_basin, basin)
            basins.remove(basin)
    basins.append(new_basin)
    

for i in range(len(heightmap)):
    add_to_basin(i)

lengths = [len(a) for a in sorted(basins,key=len)[-3:]]
print(lengths[0]*lengths[1]*lengths[2])