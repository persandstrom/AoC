import sys

input_data = [row.strip() for row in sys.stdin]
w, h = len(input_data), len(input_data[0])
trees = [int(i) for i in "".join(input_data)]

visible = 0
for i, hight in enumerate(trees):
    x, y = i%w, i//h
    visible += (
        x==0 or y==0 or x==w-1 or y==h-1 or 
        max(trees[h*(i//w):i]) < hight or
        max(trees[h*(i//w)+x+1:(y+1)*w]) < hight or
        max(trees[x:i-1:w]) < hight or
        max(trees[h*(y+1)+x::w]) < hight)

print(visible)
