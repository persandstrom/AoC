import sys
import re

input = [row.strip() for row in sys.stdin if row.strip() != '']
data = [int(nr) for nr in input[0].split(',')]
ages = [0]*9

for i in data:
    ages[i] = ages[i] + 1

for day in range(256):
    to_give_birth = ages[0]
    for i in range(1, len(ages)):
        ages[i-1] = ages[i]
    ages[6] = ages[6] + to_give_birth
    ages[8] = to_give_birth

print(sum(ages))