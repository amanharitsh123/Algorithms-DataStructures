# Find the length of longest common subsequence
# Submitted on geeksforgeeks
def solve(i,j,dp):
    if j>=m or i>=n:
        return 0
    if (i,j) in dp:
        return dp[(i,j)]
    if s1[i]==s2[j]:
        dp[(i,j)]=1+solve(i+1,j+1,dp)
    else:
        dp[(i,j)]=max(solve(i+1,j,dp),solve(i,j+1,dp))
    return dp[(i,j)]



for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    s1=input()
    s2=input()
    dp={}
    # Top Down
    # print(solve(0,0,dp))
    # Bottom UP
    dp=[[0]*(m+1) for x in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    print(dp[n][m])


# 2
# 6 6
# ABCDGH
# AEDFHR
# 3 2
# ABC
# AC
