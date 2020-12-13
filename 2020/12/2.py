import sys

actions = [(e[0], int(e[1:])) for e in sys.stdin]

WPX,WPY = 10, 1
SX, SY = 0, 0

for command, value in actions:
    if command == "N":
        WPY += value
    elif command == "S":
        WPY -= value
    elif command == "E":
        WPX += value
    elif command == "W":
        WPX -= value
    elif command == "L":
        for i in range(0,int(value/90)):
            WPX, WPY = -WPY, WPX
    elif command == "R":
        for i in range(0,int(value/90)):
            WPX, WPY = WPY, -WPX
    elif command == "F":
        SX += WPX*value
        SY += WPY*value

print(abs(SX)+abs(SY))
