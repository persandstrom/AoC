import sys

inputs = [row.strip() for row in sys.stdin]
separator = inputs.index("")
width = max([int(input.split(",")[0]) for input in inputs[:separator]])+1
height = max([int(input.split(",")[1]) for input in inputs[:separator]])+1

dots = [False]*(width*height)

for input in inputs[:separator]:
    x,y = input.split(",")
    dots[int(x) + width*int(y)] = True

instruction = inputs[separator+1]
fold_x = "x" in instruction
new_width = int(width/2) if fold_x else width
new_height = height if fold_x else int(height/2)
new_dots = ['.']*(new_width*new_height)
if fold_x:
    for i,dot in enumerate(dots):
        if i%width < new_width:
            opposite = i + width - 2*(i%width) - 1
            new_dots[i%width + new_width*int((i-i%width)/width)] = dot or dots[opposite]
else:
    for i,dot in enumerate(dots[:len(new_dots)]):
        opposite = i%width + height*width  - width- int((i - i%width)/width)*width
        new_dots[i] = dot or dots[opposite] 
dots = new_dots
width = new_width
height = new_height

print(dots.count(True))