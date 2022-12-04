import sys

def to_set(r1, r2):
    r1_min, r1_max = r1.split('-')
    r2_min, r2_max = r2.split('-')
    return (set(range(int(r1_min), int(r1_max)+1)), 
            set(range(int(r2_min), int(r2_max)+1)))

pairs = [to_set(*row.strip().split(",")) for row in sys.stdin]

print(len([
    pair for pair in pairs
    if pair[0].union(pair[1]) == max(pair[0], pair[1])]))
