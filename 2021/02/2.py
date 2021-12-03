import sys

commands = [row.strip().split() for row in sys.stdin]

horizontal = 0
depth = 0
aim = 0

def forward(val):
    global horizontal
    horizontal = horizontal + val
    global depth
    depth = depth + val * aim

def down(val):
    global aim
    aim = aim + val

def up(val):
    global aim
    aim = aim - val

for command in commands:
    globals()[command[0]](int(command[1]))

print(horizontal*depth)