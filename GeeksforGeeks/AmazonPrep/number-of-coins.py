for _ in range(int(input())):
    target,n=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    dp=[float("inf")]*target
    for j in arr:
        dp[j]=1
    for i in range(target+1):
        for j in arr:
            if j<=i:
                dp[i]=min(dp[i],1+dp[i-j])
    print(dp[target])



# 1
# 7 2
# 2 1