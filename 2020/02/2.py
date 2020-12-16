import sys
import re
from collections import namedtuple

Entry = namedtuple('Entry', 'p0, p1, ch, pwd')
entries = [Entry(*re.split('-| |,|: ', entry)) for entry in sys.stdin]
valid = sum(1 for e in entries
            if (e.pwd[int(e.p0)-1] == e.ch) ^ (e.pwd[int(e.p1)-1] == e.ch))
print(valid)
