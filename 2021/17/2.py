import sys
import re

x1, x2, y1, y2 = [int(n) for n in re.findall( "-?[0-9]+" ,[row.strip() for row in sys.stdin][0])]

hits = 0

for out_x_vel in range(0, x2+1):
    for out_y_vel in range(y1,-(y1-1)):
        vel_x = out_x_vel
        vel_y = out_y_vel
        x, y = 0, 0
        while y >= y1 and x <= x2:
            x += vel_x
            y += vel_y
            vel_x = max(0, vel_x-1)
            vel_y -= 1
            if x1 <= x <= x2 and y1 <= y <= y2:
                hits += 1
                break

print(hits)
