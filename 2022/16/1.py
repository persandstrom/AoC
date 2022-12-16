import sys
import re

valves = {}


class Situation:
    def __init__(self, me, time, rate, closed, acc_flow, last_visited):
        self.me = me
        self.time = time
        self.rate = rate
        self.closed = closed 
        self.acc_flow = acc_flow
        self.last_visited = last_visited

    def can_release(self):
        return self.me not in self.closed and valves[self.me]["flow"] > 0

    def release(self):
        return Situation(
            self.me,
            self.time + 1,
            self.rate + valves[self.me]["flow"],
            self.closed.union(set([self.me])),
            self.acc_flow + self.rate,
            [])
    
    def paths(self):
        return [
            path for path in valves[self.me]["leads"]
            if path not in self.last_visited]
    
    def move(self, to):
        return Situation(
            to,
            self.time + 1,
            self.rate,
            self.closed.copy(),
            self.acc_flow + self.rate,
            self.last_visited + [self.me]
            )

for row in sys.stdin:
    m = re.match(
        r"Valve (.*) has flow rate=(.*); tunnels? leads? to valves? (.*)",
        row)
    valves[m.group(1)] = {
            "flow": int(m.group(2)), 
            "leads": [path.strip() for path in m.group(3).split(",")]}

situations = [
    Situation("AA", 1, 0, set([]), 0, [])
    ]
times_up = 31
best_flow_at = [0]*32
best_flow = 0

while situations:
    situation = situations.pop()
    if situation.acc_flow < (3*best_flow_at[situation.time]) // 4:
        continue
    best_flow_at[situation.time] = max(
            best_flow_at[situation.time], situation.acc_flow)
    if situation.time == times_up:
        best_flow = max(best_flow, situation.acc_flow)
        continue
    if situation.can_release():
        situations.append(situation.release())
    for path in situation.paths():
        situations.append(situation.move(path)) 

print(best_flow)
