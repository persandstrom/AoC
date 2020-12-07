import sys
import re

bags = {}
re_color = re.compile(r"^\w+\ \w+")
re_contains = re.compile(r"\d+\ \w+\ \w+")

for row in sys.stdin.readlines():
    color = re_color.match(row).group()
    if color not in bags:
        bags[color] = {}
    for contain in re_contains.findall(row):
        if contain[2:] not in bags:
            bags[contain[2:]] = {}
        bags[contain[2:]][color] = 1


def get_possible_container_colors(bag, colors=set()):
    for key, value in bag.items():
        colors.add(key)
        colors.union(*get_possible_container_colors(bags[key], colors))
    return colors


print(len(get_possible_container_colors(bags["shiny gold"])))
