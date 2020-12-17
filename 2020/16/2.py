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


class Ticket:
    def __init__(self, values):
        self.values = values
        self.is_valid = True
        self.val_fields = [[] for i in range(len(values))]

    def validate(self, fields):
        for value_pos, value in enumerate(self.values):
            for field_pos, field in enumerate(fields):
                if field.validate(value):
                    self.val_fields[value_pos] += [field.name]
        self.is_valid = not [] in self.val_fields


fields = []
tickets = []
for line in sys.stdin:
    field = re.findall(r'(.*?): (\d*)-(\d*) or (\d*)-(\d*)', line)
    if field:
        fields.append(Field(*field[0]))
    if line[0].isdigit():
        tickets.append(Ticket([int(v) for v in line.strip().split(',')]))

val_fields = [[field.name for field in fields]] * len(fields)
for ticket in tickets:
    ticket.validate(fields)
    if ticket.is_valid:
        for pos, val in enumerate(ticket.val_fields):
            val_fields[pos] = [v for v in val_fields[pos] if v in val]

to_erase = ""
start_pos = -1
while sum([len(field) for field in val_fields]) != len(val_fields):
    for pos, v in enumerate(val_fields):
        if pos == start_pos:
            start_pos = -1
            to_erase = ""
        elif len(v) == 1 and start_pos == -1:
            to_erase = v[0]
            start_pos = pos
        elif (to_erase in v) and start_pos != pos:
            val_fields[pos].remove(to_erase)

field_pos = [i for i, v in enumerate(val_fields) if v[0][:3] == "dep"]

tot = 1
for i in field_pos:
    tot *= tickets[0].values[i]

print(tot)
