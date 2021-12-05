import sys
import re

input = [row.strip() for row in sys.stdin if row.strip() != '']
data = [int(nr) for nr in re.findall("[0-9]+",' '.join(input))]

x_max = max(data[::2])
y_max = max(data[1::2])

vents = [0 for i in range((x_max+1)*(y_max+1))]

def line(x0, y0, x1, y1):
    if x0 != x1 and y0 != y1: 
        return
    x, y = x0, y0
    yield(x,y)
    while x != x1 or y != y1: 
        x = x + 1 if x < x1 else x - 1 if x != x1 else x
        y = y + 1 if y < y1 else y - 1 if y != y1 else y
        yield(x,y)

for i in range(int(len(data)/4)):
    for x, y in line(*data[i*4:i*4+4]):
        p = x + y*x_max
        vents[p] = vents[p] + 1

print(len([vent for vent in vents if vent >1]))