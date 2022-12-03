import sys

rucksacks = [row.strip() for row in sys.stdin]
badges = [ 
    list(
        set(rucksacks[i*3])
        .intersection(set(rucksacks[i*3+1]))
        .intersection(set(rucksacks[i*3+2])))[0]
    for i in range(len(rucksacks)//3)]
ascii_to_prio = lambda a: a - 96 if a > 90 else a - 38
print(sum([ascii_to_prio(ord(b)) for b in badges]))
