import sys

X=1
ss=[1,1]
c=0

for op in [row.strip() for row in sys.stdin]:
    instr = op[0:4]
    if instr == "noop":
        ss.append(ss[-1:][0])
    if instr == "addx":
        ss.append(ss[-1:][0])
        ss.append(ss[-1:][0]+int(op[4:]))

print(sum([i*ss[i] for i in range(20,221,40)]))
