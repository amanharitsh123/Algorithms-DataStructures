# Top Down
def solve(i,su,total):
    if (i,su) in dp:
        return dp[(i,su)]
    if i==len(arr):
        # print("returning ",abs(total-su))
        return abs(total-2*su)
    dp[(i,su)]= min(solve(i+1,su+arr[i],total),solve(i+1,su,total))
    return dp[(i,su)]

# Bottom up
def solve_i():
    
    


for _ in range(int(input())):
    dp={}
    n=int(input())
    arr=list(map(int,input().split()))
    sum_total=0
    for x in arr:
        sum_total+=x
    print(solve(0,0,sum_total))

# 2
# 4
# 1 6 5 11
# 4
# 36 7 46 40