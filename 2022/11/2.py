import sys

items = []
operations = []
test_dividers = []
throws_to_true = []
throws_to_false = []
inspections = []

def create_op(op_string):
    def op_function(old):
        return eval(op_string)
    return op_function

for row in [row.strip() for row in sys.stdin]:
    if row.startswith("Monkey"):
        inspections.append(0)
    if row.startswith("Starting items"):
        items.append([int(item) for item in row[16:].split(",")])
    if row.startswith("Operation"):
        operations.append(create_op(row[17:]))
    if row.startswith("Test:"):
        test_dividers.append(int(row[19:]))
    if row.startswith("If true:"):
        throws_to_true.append(int(row[25:]))
    if row.startswith("If false:"):
        throws_to_false.append(int(row[25:]))

monkeys = range(len(items))

div_prod=1
for test_divider in test_dividers:
    div_prod *= test_divider

for i in range(10000):
    for monkey in monkeys:
        while items[monkey]:
            item = items[monkey].pop()
            item = operations[monkey](item) % div_prod
            inspections[monkey] += 1
            if item % test_dividers[monkey] == 0:
                items[throws_to_true[monkey]].append(item)
            else:
                items[throws_to_false[monkey]].append(item)

inspections = sorted(inspections)
print(inspections[-1]*inspections[-2])

