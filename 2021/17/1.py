import sys
import re

_, _, y1, y2 = [int(n) for n in re.findall( "-?[0-9]+" ,[row.strip() for row in sys.stdin][0])]
print(int((abs(y1)-1)*abs(y1)/2))