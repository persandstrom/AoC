import sys

data = [eval(row.strip()) for row in sys.stdin if row.strip()]

def compare(l1, l2):
    if type(l1) == int and type(l2) == int:
        return -1 if l1 < l2 else 0 if l1 == l2 else 1 
    if type(l1)==int:
        l1=[l1]
    if type(l2)==int:
        l2=[l2]
    for c in (compare(l1[i], l2[i]) for i in range(min(len(l1), len(l2)))):
        if c:
            return c
    return 1 if len(l1) > len(l2) else 0 if len(l1) == len(l2) else -1

print(sum(
    i+1 for i 
    in range(len(data)//2) 
    if compare(data[i*2], data[i*2+1]) != 1))
