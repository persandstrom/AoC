import sys
import re

bags = {}
re_color = re.compile(r"^\w+\ \w+")
re_contains = re.compile(r"\d+\ \w+\ \w+")

for row in sys.stdin.readlines():
    color = re_color.match(row).group()
    bags[color] = {}
    for contain in re_contains.findall(row):
        bags[color][contain[2:]] = int(contain[0])


def count_bags(bag):
    return sum(v + v*count_bags(bags[k]) for k, v in bag.items())


print(count_bags(bags["shiny gold"]))
