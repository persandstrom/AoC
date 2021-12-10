import sys

input = [row.strip()for row in sys.stdin]
points = []

for line in input:
    for i in range(int(len(line))):
        rep = (2+i)*" "
        line = line.replace("(" + i*" " + ")", rep).replace("[" + i*" " + "]", rep).replace("<" + i*" " + ">", rep).replace("{" + i*" " + "}", rep)
    line = line.replace(" ", "")
    if ")" not in line and "]" not in line and "}" not in line and ">" not in line:
        point = 0
        for c in line[::-1]:
            point = point*5 + 1*(c == "(") + 2*(c == "[") + 3*(c == "{") + 4*(c == "<")
        points.append(point)

points.sort()
print(points[int(len(points)/2)])