import sys


def wrapping(present):
    width, heigth, length = [int(s) for s in present.split('x')]
    areas = [width*heigth, width*length, heigth*length]
    return 2*sum(areas) + min(areas)


wrappings = [wrapping(present) for present in sys.stdin]

print(sum(wrappings))
