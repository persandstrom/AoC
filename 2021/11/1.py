import sys

input = [row.strip()for row in sys.stdin]
width = len(input[0])
energies = [int(i) for i in ''.join(input)]
total_flashed = 0

for step in range(100):
    has_flashed = []
    energies = [energy+1 for energy in energies]
    while True:
        to_flash = [index for index, energy in enumerate(energies) if energy > 9 and index not in has_flashed]
        if len(to_flash) == 0: break
        for index in to_flash:
            if index-width-1 >= 0 and (index%width)-1 >= 0: energies[index-width-1] += 1
            if index-width >= 0: energies[index-width] += 1
            if index-width+1 >= 0 and (index%width)+1 < width: energies[index-width+1] += 1
            if index-1 >= 0 and (index%width)-1 >= 0: energies[index-1] += 1
            if index+1 < len(energies) and (index%width)+1 < width: energies[index+1] += 1
            if index+width-1 < len(energies) and (index%width)-1 >= 0: energies[index+width-1] += 1
            if index+width < len(energies): energies[index+width]  += 1
            if index+width+1 < len(energies) and (index%width)+1 < width: energies[index+width+1] += 1
        total_flashed += len(to_flash)
        has_flashed += to_flash
    for index in has_flashed:
        energies[index] = 0
    
print(total_flashed)