def solve(dp,i):
    if i==len(arr):
        return 0
    if i in dp:
        return dp[i]
    if i==len(arr)-1:
        return len(arr)*arr[i]
    ind=i+1
    ans=max(arr[i+1]*(ind)+arr[i]*(ind+1)+solve(dp,i+2), arr[i]*ind+solve(dp,i+1))
    dp[i]=ans
    return ans
for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    # arr.sort()
    su=0
    dp={}
    print(solve(dp,0))
# 3
# 2
# 2 8
# 3 
# 8 2 8
# 3
# 9 10 11