import sys


class Memory:
    def __init__(self):
        self.internal = {}
        self.and_mask = 0
        self.or_mask = 0

    def set_mask(self, mask):
        self.and_mask = 0x00FFFFFFFF
        self.or_mask = 0
        for i, c in enumerate(mask[::-1]):
            if c == '1':
                self.or_mask += 2 ** i
            if c == '0':
                self.and_mask -= 2 ** i

    def __setitem__(self, index, value):
        self.internal[index] = (value & self.and_mask) | self.or_mask


mem = Memory()

for row in [row.strip() for row in sys.stdin]:
    if row[0:4] == "mask":
        mem.set_mask(row.split()[-1])
    else:
        exec(row)

print(sum(mem.internal.values()))
