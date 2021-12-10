import sys

input = [row.strip()for row in sys.stdin]
width = len(input[0])
heightmap = [int(i) for i in ''.join(input)]

def is_lowpoint(i):
    return\
        (heightmap[i] < heightmap[i-width] if i - width >= 0 else True) and\
        (heightmap[i] < heightmap[i-1] if (i-1)%width < i%width else True) and \
        (heightmap[i] < heightmap[i+1] if (i+1)%width > i%width else True) and\
        (heightmap[i] < heightmap[i+width] if i + width < len(heightmap) else True)


print(sum([heightmap[p]+1 for p in range(len(heightmap)) if is_lowpoint(p)]))