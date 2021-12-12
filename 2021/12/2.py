import sys

input = [row.strip() for row in sys.stdin]

destinations = [row.split("-") for row in input]
destinations += [[destination[1], destination[0]] for destination in destinations]
destinations = [destination for destination in destinations if destination[1] != "start"]

trips = [[True, "start"]]
finished_trips = []

while len(trips) != 0:
    for trip in trips:
        for destination in [destination[1] for destination in destinations if destination[0] == trip[-1]]:
            if destination == "end":
                finished_trips += [trip[1:] + [destination]]
            elif destination.islower() and destination in trip and trip[0]:
                trips += [[False] + trip[1:] + [destination]]
            elif destination.islower and destination not in trip:
                trips += [trip + [destination]]
            elif destination.isupper():
                trips += [trip + [destination]]

        trips.remove(trip)
        
print(len(finished_trips))