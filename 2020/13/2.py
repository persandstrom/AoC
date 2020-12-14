import sys

_, r2 = sys.stdin
busses = [bus.strip() for bus in r2.split(',')]
step = int(busses[0])
timestamp = step + 1

for bus in busses[1:]:
    if bus.isdigit():
        busnr = int(bus)
        while timestamp % busnr != 0:
            timestamp += step
        step *= busnr
    timestamp += 1

print(timestamp - len(busses))
