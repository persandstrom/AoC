import sys

repetitions = 5
inputs = [row.strip() for row in sys.stdin]
width = len(inputs[0])*repetitions
risks = [int(c) for c in ''.join(inputs)]
modified = [False for _ in range(len(risks)*repetitions*repetitions)]
modified[0] = True
min_risk = [100000 for _ in range(len(risks)*repetitions*repetitions)]
min_risk[0] = 0

def get_risk(index):
    y = index // width % len(inputs)
    x = index % width % len(inputs[0])
    x_rep = index % width // len(inputs[0])
    y_rep = index // width // len(inputs)
    return (risks[x+(y*len(inputs[0]))] + x_rep + y_rep - 1)%9 + 1

risks = [get_risk(i) for i in range(len(risks)*repetitions*repetitions)]

while any(modified):
    for index, v in enumerate(modified):
        if not v:
            continue
        modified[index] = False
        if index-width >= 0 and min_risk[index] + risks[index-width] < min_risk[index-width]:
            min_risk[index-width] = min_risk[index] + risks[index-width]
            modified[index-width] = True
        if index-1 >= 0 and (index%width)-1 >= 0 and min_risk[index] + risks[index-1] < min_risk[index-1]:
            min_risk[index-1] = min_risk[index] + risks[index-1]
            modified[index-1] = True
        if index+1 < len(modified) and (index%width)+1 < width and min_risk[index] + risks[index+1] < min_risk[index+1]:
            min_risk[index+1] = min_risk[index] + risks[index+1]
            modified[index+1] = True
        if index+width < len(modified) and min_risk[index] + risks[index+width] < min_risk[index+width]:
            min_risk[index+width] = min_risk[index] + risks[index+width]
            modified[index+width] = True
        
print(min_risk[-1])