import sys


def ribbon(present):
    width, heigth, length = [int(s) for s in present.split('x')]
    sides = sorted([width, heigth, length])
    return 2*sum(sides[0:2]) + width*heigth*length


ribbons = [ribbon(present) for present in sys.stdin]

print(sum(ribbons))
