for _  in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    dp = {}
    
    for i in range(n):
        dp[i]=1

    # print(dp)
    # Solving in Bottom Up fashion
    final_ans=1
    for i in range(1,n):
        for j in range(i,-1,-1):
            if arr[i]>arr[j]:
                dp[i]=max(dp[i],1+dp[j])
            final_ans=max(final_ans,dp[i])
    print(final_ans)

