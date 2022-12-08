import sys

input_data = [row.strip() for row in sys.stdin]
w, h = len(input_data), len(input_data[0])
trees = [int(i) for i in "".join(input_data)]

def los(direction, i):
    l = 0
    for t in direction:
        l+=1
        if t >= trees[i]:
            return l
    return l

score = 0

for i in range(0, w*h):
    x, y = i%w, i//h    
    score = max(score,
        los(trees[h*(i//w):i][::-1], i) *
        los(trees[h*(i//w)+x+1:(y+1)*w], i) *
        los(trees[x:i-1:w][::-1], i) *
        los(trees[h*(y+1)+x::w], i))

print(score)
