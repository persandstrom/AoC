import sys

altitudes_str = [row.strip() for row in sys.stdin]
width = len(altitudes_str[0])
height = len(altitudes_str)
altitudes = [ord(a)-97 for a in "".join(altitudes_str)]
start_pos = altitudes.index(-14)
end_pos = altitudes.index(-28)
altitudes[start_pos] = ord("a")-97
altitudes[end_pos] = ord("z")-97

visited = []

starting_positions = [i for i,a in enumerate(altitudes) if a == ord('a') - 97] 

visited = []
to_visit = [(end_pos, 0)]
while(True):
    pos, steps = to_visit[0]
    del to_visit[0]
    if pos in starting_positions:
        print(steps)
        exit(0)
    
    if pos in visited:
        continue
    
    curr_alt = altitudes[pos]
    if not pos%width-1 < 0 and altitudes[pos-1] + 1 >= curr_alt:
        to_visit.append((pos-1, steps+1))
    if (not pos%width+1 >= width) and altitudes[pos+1] + 1 >= curr_alt:
        to_visit.append((pos+1, steps+1))
    if pos-width >= 0 and altitudes[pos-width] + 1 >= curr_alt:
        to_visit.append((pos-width, steps+1))
    if pos+width < len(altitudes) and altitudes[pos+width] + 1 >= curr_alt:
        to_visit.append((pos+width, steps+1))
    visited.append(pos)
