import sys
import re

stacks = []
for row in sys.stdin:
    if not row.strip():
        break
    if not row[1].isdigit():
        crates_row = row[1::4]
        for i in range(0,len(crates_row)):
            if len(stacks) < i+1:
                stacks.append([])
            if crates_row[i].strip():
                stacks[i].append(crates_row[i])

for row in sys.stdin:
    m = re.match(r"move ([0-9]+) from ([0-9]+) to ([0-9]+)", row)
    amount = int(m.group(1))
    from_c = int(m.group(2)) - 1
    to_c = int(m.group(3)) - 1
    to_move = stacks[from_c][:amount:]
    to_move.reverse()
    stacks[to_c] = to_move + stacks[to_c]
    del stacks[from_c][:amount:]

print("".join([stack[0] for stack in stacks]))
