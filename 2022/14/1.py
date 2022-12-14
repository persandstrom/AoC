import sys

max_x, min_x, max_y = 0, sys.maxsize, 0

paths = []

for row in (row.strip() for row in sys.stdin):
    coords = row.split(" -> ")
    points = []
    for coord in coords:
        x_str, y_str = coord.split(",")
        x, y = int(x_str), int(y_str)
        max_x = max(x, max_x)
        min_x = min(x, min_x)
        max_y = max(y, max_y)
        points.append((x,y))
    paths.append(points)
width = max_x - min_x + 1
height = max_y+1

cave = ['.']*width*height
cave[500-min_x] = '+'

for path in paths:
    px, py = path[0][0]-min_x, path[0][1]
    for i in range(1, len(path)):
        x, y = path[i][0]-min_x, path[i][1]
        step = width if py != path[i][1] else 1
        direction = 1 if x-px+y-py > 0 else -1
        for p in range(abs(px-x) + abs(py-y) + 1):
            cave[py*width + px + p*step*direction] = '#'
        px, py = x, y

in_abyss = False
while(not in_abyss):
    sand_pos = 500-min_x
    while(True):
        down = sand_pos+width
        left = sand_pos+width-1
        right = sand_pos+width+1
        
        if down > len(cave):
            cave[sand_pos] = "."
            in_abyss = True
            break
        
        if cave[down] == "#" or cave[down] == "o":
            if left//width != sand_pos//width + 1:
                cave[sand_pos] = "."
                in_abyss = True
                break
            elif cave[left] == ".":
                cave[sand_pos] = "."
                sand_pos = left
                cave[sand_pos] = "o"
                next
            elif right//width != sand_pos//width + 1:
                cave[sand_pos] = "."
                in_abyss = True
                break
            elif cave[right] == ".":
                cave[sand_pos] = "."
                sand_pos = right
                cave[sand_pos] = "o"
                next
            else:
                break
        
        elif cave[sand_pos + width] == ".":
            cave[sand_pos] = "."
            sand_pos = sand_pos+width
            cave[sand_pos] = "o"
            next
    
print(sum([1 for pos in cave if pos == "o"]))
