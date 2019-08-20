# Top Down DP 
# Third state indicates if the string is in continuation with any previous substring
# con is either 0 or 1 
def solve(i,j,con,dp):
    if (i,j,con) in dp:
        return dp[(i,j,con)]
    
    if i>=n or j>=m:
        return 0
    ans=0
    if con==1:
        if s1[i]==s2[j]:
            ans=1+solve(i+1,j+1,1,dp)
        else:
            ans=0
        dp[(i,j,con)]=ans
    else:      
        if s1[i]==s2[j]:
            ans=1+solve(i+1,j+1,1,dp)
        ans=max(ans,solve(i+1,j,0,dp),solve(i,j+1,0,dp))
        dp[(i,j,con)]=ans
    return dp[(i,j,con)]

for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    s1=input()
    s2=input()
    dp={}

    print(solve(0,0,0,dp))
    ans=0
    # Bottom UP
    # using longest common suffix
    dp=[[0]*(m+1) for x in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-2]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=0
            ans=max(ans,dp[i][j])
    print(ans)
    


# 2
# 6 6
# ABCDGH
# ACDGHR
# 3 2
# ABC
# AC