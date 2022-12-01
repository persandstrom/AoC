import sys

calories = [row.strip() for row in sys.stdin]

elf_calories_list = []
elf_calories = 0
for row in calories:
    if not row:
        elf_calories_list.append(elf_calories)
        elf_calories = 0
    else:
        elf_calories += int(row)
elf_calories_list.append(elf_calories)

print(sum(sorted(elf_calories_list)[-3:]))
