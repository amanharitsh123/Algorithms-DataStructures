for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    dp=[[1,1] for x in range(n)]
    ans=1
    for i in range(1,n):
        x=arr[i]
        for j in range(i-1,-1,-1):
            if arr[j]<x:
                dp[i][0]=max(1+dp[j][0],dp[i][0]) # Contributing to increasing part
            elif arr[j]>x:
                dp[i][1]=max(1+dp[j][1],dp[i][1]) # Contibuting to decreasing part or starting decreasing part
                dp[i][1]=max(1+dp[j][0],dp[i][1])
        ans=max(ans,max(dp[i]))
                
    print(ans)