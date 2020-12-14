import sys


class Memory:
    def __init__(self):
        self.internal = {}
        self.and_mask = 0
        self.f_masks = []

    def set_mask(self, mask):
        self.or_mask = 0
        self.f_masks = [0]
        for i, c in enumerate(mask[::-1]):
            if c == '1':
                self.or_mask += 2 ** i
            if c == 'X':
                new_mask = 2 ** i
                new_masks = []
                for f_mask in self.f_masks:
                    new_masks.append(new_mask+f_mask)
                self.f_masks = self.f_masks + new_masks

    def __setitem__(self, index, value):
        for f_mask in self.f_masks:
            self.internal[(index | self.or_mask) ^ f_mask] = value


mem = Memory()

for row in [row.strip() for row in sys.stdin]:
    if row[0:4] == "mask":
        mem.set_mask(row.split()[-1])
    else:
        exec(row)

print(sum(mem.internal.values()))
