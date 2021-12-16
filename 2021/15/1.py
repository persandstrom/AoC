import sys

inputs = [row.strip() for row in sys.stdin]
width = len(inputs[0])
risks = [int(c) for c in ''.join(inputs)]
modified = [False for _ in risks]
modified[0] = True
min_risk = [1000 for _ in risks]
min_risk[0] = 0

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
        if index+1 < len(risks) and (index%width)+1 < width and min_risk[index] + risks[index+1] < min_risk[index+1]:
            min_risk[index+1] = min_risk[index] + risks[index+1]
            modified[index+1] = True
        if index+width < len(risks) and min_risk[index] + risks[index+width] < min_risk[index+width]:
            min_risk[index+width] = min_risk[index] + risks[index+width]
            modified[index+width] = True
        
print(min_risk[-1])