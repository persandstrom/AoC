import sys

input = [row.strip() for row in sys.stdin if row.strip() != '']
crabs = [int(nr) for nr in input[0].split(',')]

triangular_number = lambda x: int(x*(x+1)/2) 
best_fuel = min([sum(triangular_number(abs(pos - crab_pos)) for crab_pos in crabs) for pos in range(max(crabs))])
    
print(best_fuel)