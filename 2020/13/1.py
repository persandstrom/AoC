import sys

r1, r2 = sys.stdin
earliest = int(r1)
busses = [int(bus) for bus in r2.split(',') if bus.isdigit()]
next_departure = sorted([(bus - earliest % bus, bus) for bus in busses])
print(next_departure[0][0] * next_departure[0][1])
