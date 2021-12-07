import sys

input = [row.strip() for row in sys.stdin if row.strip() != '']
crabs = [int(nr) for nr in input[0].split(',')]

best_fuel = min([sum(abs(pos - crab_pos) for crab_pos in crabs) for pos in range(max(crabs))])
    
print(best_fuel)