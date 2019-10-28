for _ in range(int(input())):
    n=int(input())
    dp=[1]*(n+1)
    for i in range(2,n+1):
        dp[i]+=dp[i-2]
    print(dp[n])

# 2
# 4
# 5