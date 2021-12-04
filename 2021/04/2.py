import sys

input = [row.strip() for row in sys.stdin if row.strip() != '']
called_numbers = [int(i) for i in input.pop(0).split(",")]
boards = [int(num) for num in ' '.join(input).split()]
marked = [False for i in range(len(boards))]
bingoed = set()
last = 0


def dot(called):
    for i, board_val in enumerate(boards):
        marked[i] = True if called == board_val or marked[i] == 1 else False
    for i in [i for i in range(len(marked)) if int(i/25) not in bingoed]:
        if i%5 == 0 and all(marked[i:i+5]):
            bingoed.add(int(i/25))
        if i%25 < 5 and all(marked[i:i+25:5]):
            bingoed.add(int(i/25))

for called in called_numbers:
    dot(called)
    if len(bingoed) < len(boards)/25 - 1:
        continue
    if len(bingoed) == len(boards)/25 - 1:
        last = (set([i for i in range(int(len(boards)/25))]) - bingoed).pop()
        continue
    sum = sum([boards[i] if marked[i] == 0 else 0 for i in range(last*25, last*25 + 25)])
    print(sum*called)
    exit(0)
        
    

        
