import sys

data = sys.stdin.read().split("\n\n")
matches = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
print(sum(1 for r in data if all(x in r for x in matches)))
