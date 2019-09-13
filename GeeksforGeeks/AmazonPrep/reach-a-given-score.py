for _ in range(int(input())):
    n=int(input()) + 10
    dp=[0]*(n+1)
    three=3
    while three <n+1:
        dp[three]+=1
        three=three+3
    # print(dp)
    dp[5]=1
    for i in range(5,n+1):
        dp[i]+=dp[i-5]
    dp[10]+=1
    for i in range(10,n+1):
        dp[i]+=dp[i-10]
        
    
    print(dp[n-10])

# 3
# 8
# 20
# 13