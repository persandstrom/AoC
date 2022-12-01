import sys

calories = [row.strip() for row in sys.stdin]

max_elf_calories, elf_calories = 0, 0
for row in calories:
    elf_calories = elf_calories + int(row) if row else 0
    max_elf_calories = max(max_elf_calories, elf_calories)
max_elf_calories = max(max_elf_calories, elf_calories)

print(max_elf_calories)
