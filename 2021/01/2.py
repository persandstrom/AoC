import sys

measurements = [int(row.strip()) for row in sys.stdin]

count = 0
for i in range(1, len(measurements)-2):
    if sum(measurements[i:i+3]) > sum(measurements[i-1:i+2]):
        count = count + 1

print(count)
