import sys

actions = [(e[0], int(e[1:])) for e in sys.stdin]

X = 0
Y = 0
H = 90

for command, value in actions:
    if command == "N":
        Y += value
    elif command == "S":
        Y -= value
    elif command == "E":
        X += value
    elif command == "W":
        X -= value
    elif command == "L":
        H -= value
    elif command == "R":
        H += value
    elif command == "F":
        X += value if H % 360 == 90 else 0
        X -= value if H % 360 == 270 else 0
        Y += value if H % 360 == 0 else 0
        Y -= value if H % 360 == 180 else 0

print(abs(X)+abs(Y))
