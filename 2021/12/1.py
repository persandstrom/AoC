import sys

paths = [row.strip()for row in sys.stdin]

trips = [["start"]]

while len([trip for trip in trips if trip[-1] != "end"]) != 0:
    for trip in [trip for trip in trips if trip[-1] != "end"]:
        destinations = [path.replace(trip[-1] + "-", "").replace("-" + trip[-1], "") for path in paths if trip[-1] in path.split("-")]
        trips += [trip + [destination] for destination in destinations if not (destination.islower() and destination in trip)]
        trips.remove(trip)

print(len(trips))