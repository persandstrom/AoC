import sys
import re

data = sys.stdin.read().split("\n\n")
matches = [
        "byr:(19[2-9][0-9]|200[0-2])",
        "iyr:20(1[0-9]|20)",
        "eyr:20(2[0-9]|30)",
        "hgt:((1([5-8][0-9]|9[0-3]))cm|(59|6[0-9]|7[0-6])in)",
        "hcl:#([0-9]|[a-f]){6}",
        "ecl:(amb|blu|brn|gry|grn|hzl|oth)",
        "pid:[0-9]{9}"
        ]
print(sum(1 for r in data if all(re.search(x+"($| |\n)", r) for x in matches)))
