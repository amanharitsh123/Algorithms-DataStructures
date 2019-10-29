# Recursive Solution O(3^n) 
def solve_r(i,j):
    if i>=n:
        return m-j
    if j>=m:
        return n-i
    if i<n and j<m and s1[i]==s2[j]:
        return solve(i+1,j+1)
    return 1+min(solve(i+1,j),solve(i,j+1),solve(i+1,j+1))

# Iterative Solution O(n**2)
def solve_i():
    dp = {}
    for i in range(n+1):
        dp[(i,0)]=i
    for j in range(m+1):
        dp[(0,j)]=j
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[(i,j)]=dp[(i-1,j-1)]
            else:
                dp[(i,j)]=1+min(dp[(i-1,j-1)],dp[(i-1,j)],dp[(i,j-1)])
    return dp[(n,m)]
            
    

for i in range(int(input())):
    n,m=list(map(int,input().split()))
    s1,s2=input().split()
    print(solve_i())
    

# 1
# 4 5
# geek gesek

# allowed operations are Insert,delete and update