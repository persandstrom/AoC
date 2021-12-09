import sys
import re

input = [row.strip().split('|')[1] for row in sys.stdin]

unique_len = lambda len: len == 7 or len == 4 or len == 3 or len == 2
patterns = [pattern for pattern in re.findall("[a-g]+", ' '.join(input)) if unique_len(len(pattern))]

print(len(patterns))