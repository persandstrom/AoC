import sys

s = sorted([int(r
            .replace('F', '0').replace('B', '1')
            .replace('L', '0').replace('R', '1'), 2)
            for r in sys.stdin])
print(next(i+1+s[0] for i in range(len(s)) if s[i]+1 != s[i+1]))
