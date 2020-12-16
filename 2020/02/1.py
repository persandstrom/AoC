import sys
import re
from collections import namedtuple

Entry = namedtuple("Entry", "min, max, ch, pwd")
entries = [Entry(*re.split('-| |,|: ', entry)) for entry in sys.stdin]
valid = sum(1 for e in entries if int(e.min) <= e.pwd.count(e.ch) <= int(e.max))
print(valid)
