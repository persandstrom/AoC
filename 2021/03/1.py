import sys

report = [row.strip() for row in sys.stdin]

sum = [0 for i in range(len(report[0]))]

for row in report:
    for i in range(len(row)):
        sum[i] = sum[i] + (1 if row[i] == "1" else -1)

gamma = int(''.join(["1" if x>0 else "0" for x in sum]),2)
epsilon = int(''.join(["1" if x<0 else "0" for x in sum]),2)

print(gamma*epsilon)
