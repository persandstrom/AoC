import sys

measurements = [int(row.strip()) for row in sys.stdin]

count = 0
for i in range(1, len(measurements)):
    if measurements[i] > measurements[i-1]:
        count = count + 1

print(count)
