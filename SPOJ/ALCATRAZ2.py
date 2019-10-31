
def solve(mask,i):
    if i==len(pairs):
        total = 0
        for i in range(8):
            if mask & 1<<i:
                total += arr[i]
        return total
    x,y = pairs[i]
    if mask & 1<<x and mask & 1<<y:
        return max(solve(mask^1<<x,i+1),solve(mask^1<<y,i+1))
    else:
        return solve(mask,i+1)

arr = list(map(int,input().split()))
p = int(input())
pairs = []

for x in range(p):
    t = list(map(int,input().split()))
    t[0] -= 1
    t[1] -= 1
    pairs.append(t)

print(solve(2**8-1,0))
