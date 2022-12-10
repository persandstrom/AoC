import sys

ss=[1,1]

for op in [row.strip() for row in sys.stdin]:
    instr = op[0:4]
    if instr == "noop":
        ss.append(ss[-1:][0])
    if instr == "addx":
        ss.append(ss[-1:][0])
        ss.append(ss[-1:][0]+int(op[4:]))

def draw(i, x):
    return "#" if i%40 in range(x-1, x+2) else "."

out = [draw(i, x) for i, x in enumerate(ss[1:])]

for i in range(0, 240, 40):
    print("".join(out[i:i+40]))
