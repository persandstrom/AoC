import sys

inputs = [row.strip() for row in sys.stdin]

polymer = inputs[0]
rules = { inputs[i][0:2]:inputs[i][6] for i in range(2, len(inputs)) }

char_count = {}
for c in polymer:
    char_count[c] = char_count[c] + 1 if c in char_count else 1

combinations = {}
for i in range(len(polymer)-1):
    combination = polymer[i:i+2] 
    combinations[combination] = combinations[combination] + 1 if combination in combinations else 1

for _ in range(40):
    new_combinations = {}
    for k,v in combinations.items():
        insertion = rules[k]
        new_comb_1, new_comb_2 = k[0]+insertion, insertion+k[1]
        char_count[insertion] = char_count[insertion] + v if insertion in char_count else v
        new_combinations[new_comb_1] = new_combinations[new_comb_1] + v if new_comb_1 in new_combinations else v
        new_combinations[new_comb_2] = new_combinations[new_comb_2] + v if new_comb_2 in new_combinations else v
    combinations = new_combinations

print(max(char_count.values()) - min(char_count.values()))

