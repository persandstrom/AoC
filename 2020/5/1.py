import sys

seats = [int(r
         .replace('F', '0').replace('B', '1')
         .replace('L', '0').replace('R', '1'), 2)
         for r in sys.stdin]
print(max(seats))
