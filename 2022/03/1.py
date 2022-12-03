import sys

rucksacks = [row.strip() for row in sys.stdin]
shared = [
    list(set(r[:len(r)//2]).intersection(r[len(r)//2:]))[0]
    for r
    in rucksacks]
ascii_to_prio = lambda a: a - 96 if a > 90 else a - 38
print(sum([ascii_to_prio(ord(c)) for c in shared]))
