import sys

input = [row.strip() for row in sys.stdin if row.strip() != '']
called_numbers = [int(i) for i in input.pop(0).split(",")]
boards = [int(num) for num in ' '.join(input).split()]
marked = [False for i in range(len(boards))]

def dot(called):
    for i, board_val in enumerate(boards):
        marked[i] = True if called == board_val or marked[i] == 1 else False
    for i in range(len(marked)):
        if i%5 == 0 and all(marked[i:i+5]):
            return int(i/25)
        if i%25 < 5 and all(marked[i:i+25:5]):
            return int(i/25)
    return -1

for called in called_numbers:
    bingo = dot(called)
    if bingo == -1:
        continue
    sum = sum([boards[i] if marked[i] == 0 else 0 for i in range(bingo*25, bingo*25 + 25)])
    print(sum*called)
    exit(0)
        
    

        
