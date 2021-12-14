import sys

inputs = [row.strip() for row in sys.stdin]
polymer = inputs[0]

rules = { inputs[i][0:2]:inputs[i][6] for i in range(2, len(inputs)) }

for _ in range(10):
    for i, e in reversed(list(enumerate(polymer[:-1]))):
        pair = polymer[i:i+2]
        if pair in rules:
            polymer = polymer[:i+1] + rules[pair] + polymer[i+1:]

char_count = {}
for c in polymer:
    char_count[c] = char_count[c] + 1 if c in char_count else 1
    
print(max(char_count.values()) - min(char_count.values()))