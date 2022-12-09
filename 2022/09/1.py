import sys
motions = [row.strip() for row in sys.stdin]

visited = set(["0,0"])
h, t = [0,0], [0,0]

def follow(h, t):
    diff = [h[0]-t[0], h[1]-t[1]]
    if abs(diff[0])<2 and abs(diff[1])<2:
        return t
    min_diff = 2 if diff[0]==0 or diff[1]==0 else 1
    return [
        t[0]+(diff[0]>=min_diff)-(diff[0]<=-min_diff),
        t[1]+(diff[1]>=min_diff)-(diff[1]<=-min_diff)]
    

def move(h, d):
    if d=="R":
        return [h[0]+1,h[1]]
    if d=="U":
        return [h[0], h[1]+1]
    if d=="L":
        return [h[0]-1, h[1]]
    if d=="D":
        return [h[0], h[1]-1]
    

for motion in motions:
    d = motion[0]
    for _ in range(0, int(motion[2:])):
        h=move(h,d)
        t=follow(h,t)
        visited = visited.union([",".join([str(n) for n in t])])

print(len(visited))
