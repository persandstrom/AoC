import sys

commands = [row.strip().split() for row in sys.stdin]

horizontal = 0
depth = 0

def forward(val):
    global horizontal
    horizontal = horizontal + val

def down(val):
    global depth
    depth = depth + val

def up(val):
    global depth
    depth = depth - val

for command in commands:
    globals()[command[0]](int(command[1]))

print(horizontal*depth)