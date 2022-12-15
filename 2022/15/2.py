import sys
import re
from bitarray import bitarray

points = []

for row in (row.strip() for row in sys.stdin):
    m = re.search(r"Sensor at x=(-?\d*), y=(-?\d*): "
                  r"closest beacon is at x=(-?\d*), y=(-?\d*)",
                  row)
    sx, sy = int(m.group(1)), int(m.group(2))
    bx, by = int(m.group(3)), int(m.group(4))
    dist = abs(sx - bx) + abs(sy - by)
    points.append((sx,sy,dist))

max_val = 4000000
all_vals = bitarray(max_val)
all_vals.setall(1)

for i in range(0,max_val):
    ranges = all_vals.copy()
    for point in points:
        y_dist = abs(point[1] - i)
        if point[2] <= y_dist:
            continue
        spread = abs(point[2] - y_dist)
        ranges[max(0,point[0]-spread):min(max_val, point[0]+spread+1)] = False
    if ranges.count(1) > 0:
        x = ranges.index(True)
        print(x*4000000 + i)
        exit(0)

