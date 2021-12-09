import sys
import re

input = [re.findall("[a-g]+",row.strip()) for row in sys.stdin]

s = 0

for patterns in input:
    one = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 2][0])
    four = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 4][0])
    seven = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 3][0])
    eight = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 7][0])
    three = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 5 and len(set(seven + pattern)) == 5][0])
    nine = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 6 and len(set(three + pattern)) == 6][0])
    five = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 5 and set(one + pattern) == set(nine)][0])
    two = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 5 and len(set(four + pattern)) == 7][0])
    zero = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 6 and len(set(five + pattern)) == 7][0])
    six = ''.join([sorted(pattern) for pattern in patterns[0:10] if len(pattern) == 6 and len(set(seven + pattern)) == 7][0])
    numbers = {zero: "0", one: "1", two: "2", three: "3", four: "4", five: "5", six: "6", seven: "7", eight: "8", nine: "9"}
    s = s + int(''.join([numbers[''.join(sorted(digit))] for digit in patterns[-4:]]))

print(s)