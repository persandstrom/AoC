import sys
from functools import cmp_to_key

data = [eval(row.strip()) for row in sys.stdin if row.strip()]
data.append([[2]])
data.append([[6]])


def compare(l1, l2):
    if type(l1) == int and type(l2) == int:
        return -1 if l1 < l2 else 0 if l1 == l2 else 1 
    if type(l1)==int:
        l1=[l1]
    if type(l2)==int:
        l2=[l2]
    for c in [compare(l1[i], l2[i]) for i in range(min(len(l1), len(l2)))]:
        if c!=0:
            return c
    return 1 if len(l1) > len(l2) else 0 if len(l1) == len(l2) else -1

data_sorted = sorted(data, key=cmp_to_key(compare))

i1, i2 = data_sorted.index([[2]])+1, data_sorted.index([[6]])+1

print(i1*i2)

