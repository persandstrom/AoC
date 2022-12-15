import sys
import re

points = []

scan_row = 2000000
scanned_pos = set([])
occupied__pos = set([])

for row in (row.strip() for row in sys.stdin):
    m = re.search(r"Sensor at x=(-?\d*), y=(-?\d*): "
                  r"closest beacon is at x=(-?\d*), y=(-?\d*)",
                  row)
    sx, sy = int(m.group(1)), int(m.group(2))
    bx, by = int(m.group(3)), int(m.group(4))
    dist = abs(sx - bx) + abs(sy - by)
    points.append((sx,sy,dist))
    if sy == scan_row:
        occupied__pos.add(sx)
    if by == scan_row:
        occupied__pos.add(bx)


for point in points:
    y_dist = abs(point[1] - scan_row)
    if point[2] <= y_dist:
        continue

    spread = abs(point[2] - y_dist)
    scanned_pos = scanned_pos.union(
        set(range(point[0]-spread, point[0]+spread+1)))

print(len(scanned_pos - occupied__pos))
    

    
    

