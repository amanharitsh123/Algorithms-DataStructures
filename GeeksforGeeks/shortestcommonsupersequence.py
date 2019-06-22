# Recursive Simple Solution
def solve_recursive(n,m):
    global dp
    if (n,m) in dp:
        return dp[(n,m)]
    if n==-1 and m==-1:
        return 0
    
    if n==-1:
        return m+1
    
    if m==-1:
        return n+1
    
    if s1[n]==s2[m]:
        dp[(n,m)]=1+solve_recursive(n-1,m-1)
        return dp[(n,m)]
    dp[(n,m)]=1+min(solve_recursive(n-1,m) , solve_recursive(n,m-1))
    return dp[(n,m)]

# Iterative Solution 
def solve_iterative():
    dp=[ [0 for x in range(m+1)] for x in range(n+1) ]
    
    # Second string is empty
    for i in range(n+1):
        dp[i][0]=i
    
    # First string is empty
    for i in range(m+1):
        dp[0][i]=i
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j])
    return dp[n][m]


for _ in range(int(input())):
    s1,s2=input().split()
    dic={}
    for x in s1:
        dic[x]=1 
    for y in s2:
        dic[y]=1
    dp={}
    n=len(s1)
    m=len(s2)
    print(solve_iterative())
        