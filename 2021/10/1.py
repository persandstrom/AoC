import sys

input = [row.strip()for row in sys.stdin]
points = 0

for line in input:
    for i in range(int(len(line))):
        rep = (2+i)*" "
        line = line.replace("(" + i*" " + ")", rep).replace("[" + i*" " + "]", rep).replace("<" + i*" " + ">", rep).replace("{" + i*" " + "}", rep)
    line = line.replace("(", " ").replace("[", " ").replace("{", " ").replace("<", " ")
    pos = len(line) - len(line.lstrip())
    if(pos != len(line)):
        char = line[pos]
        points = points + 3*(char == ")") + 57*(char == "]") + 1197*(char == "}") + 25137*(char == ">")
    

print(points)