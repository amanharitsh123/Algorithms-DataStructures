diff=10**18
k=0
cursum=[]
memo={}
su=0
ans_mask=0
def foo(target, i):
    global diff
    if target <= 0 or i==0:
        if target<=0:
            target=abs(target)
            print("target is", target)
            diff=min(diff, abs(su-2*(su//2+target)))
        else:
            diff=min(diff, abs(su-2*(su//2-target)))
        return diff
    
    if (target, i) in memo:
        return memo[(target, i)]

    if diff==su%2:
        return 0
    
    if cursum[i-1]<=target:
        return foo(target-cursum[i-1], 0)
    
    memo[(target, i)]=min(foo(target-(i)**k, i-1), foo(target, i-1))
    memo[(target, i)]=min(memo[(target, i)], diff)
    return memo[(target, i)]

def solve(n, k):
    global su
    for i in range(1, n+1):
        su+=(i**k)
    print(su)
    target=su//2
    return foo(target, n)
    dp=[[False for i in range(target+1)] for _ in range(n+1)]
    mask=[[0 for i in range(target+1)] for _ in range(n+1)]
    # Base case
    for i in range(n+1):
        dp[i][0]=True

    for i in range(1, n+1):
        print("processing ", i)
        for cursum in range(1, target+1):
            if cursum<(i**k):
                dp[i][cursum]=dp[i-1][cursum]
                continue
            diff=cursum-i**k
            if dp[i-1][diff]:
                dp[i][cursum]=True
                mask[i][cursum]=mask[i-1][cursum] | 1<<i
            else:
                dp[i][cursum]=dp[i-1][cursum]
                mask[i][cursum]=mask[i-1][cursum]
    ans_mask=0
    ans_sum=0
    for j in range(target, -1, -1):
        if dp[n][j]:
            ans_sum=j
            ans_mask=mask[n][j]
            break
    print("ans is ", su-2*ans_sum)

for i in range(10000):
    n=int(input())
    cursum=[]
    k=4
    cursum=[i**k for i in range(1, n+1)]
    for i in range(1, n):
        cursum[i]+=cursum[i-1]
    diff=10**18
    su=0
    memo={}
    print(solve(n, 4))
    print(diff)
