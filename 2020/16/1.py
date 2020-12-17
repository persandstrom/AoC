import sys
import re
from collections import namedtuple


class Field:
    def __init__(self, name, lb1, ub1, lb2, ub2):
        self.name = name
        self.lb1 = int(lb1)
        self.ub1 = int(ub1)
        self.lb2 = int(lb2)
        self.ub2 = int(ub2)

    def validate(self, value):
        return self.lb1 <= value <= self.ub1 or self.lb2 <= value <= self.ub2


fields = []
tickets = []
for line in sys.stdin:
    field = re.findall(r'(.*?): (\d*)-(\d*) or (\d*)-(\d*)', line)
    if field:
        fields.append(Field(*field[0]))
    if line[0].isdigit():
        tickets.append([int(value) for value in line.strip().split(',')])

invalid = []
for ticket in tickets[1:]:
    for value in ticket:
        valid = False
        for field in fields:
            valid |= field.validate(value)
        if not valid:
            invalid.append(value)


print(sum(invalid))
