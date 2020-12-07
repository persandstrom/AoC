import sys

groups = sys.stdin.read().split("\n\n")
print(sum(len(set(group.replace('\n', ''))) for group in groups))
