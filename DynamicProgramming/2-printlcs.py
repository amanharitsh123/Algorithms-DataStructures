# Find the length of longest common subsequence 
# Top Down Solution
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

# Print one LCS
def printlcs(i,j,st):
    if i==0 or j==0:
        return 
    if s1[i-1]==s2[j-1]:
        st.append(s1[i-1])
        printlcs(i-1,j-1,st)
    else:
        if dp[i-1][j] >= dp[i][j-1]:
            printlcs(i-1,j,st)
        else:
            printlcs(i,j-1,st)

# Print all lcs
def PrintAllLcs(i,j,st):
    if i==0 or j==0:
        print("".join(st[::-1]),end=" ")
        return

    if s1[i-1]==s2[j-1]:
        st.append(s1[i-1])
        PrintAllLcs(i-1,j-1,st)
        st.pop()
    else:
        if dp[i-1][j] > dp[i][j-1]:
            PrintAllLcs(i-1,j,st)
        elif dp[i-1][j] < dp[i][j-1]:
            PrintAllLcs(i,j-1,st)
        else:
            PrintAllLcs(i-1,j,st)
            PrintAllLcs(i,j-1,st)



for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    s1=input()
    s2=input()
    dp={}
    
    # print(solve(0,0,dp))
    
    # Bottom UP
    dp=[[0]*(m+1) for x in range(n+1)]
    parent=[i for i in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    print(dp[n][m])
    st=[]
    printlcs(n,m,st) # Print One LCS
    print("".join(st[::-1]))
    PrintAllLcs(n,m,[]) # Print All LCS


# 2
# 6 6
# ABCDGH
# AEDFHR
# 3 2
# ABC
# AC
# 7 6
# ABCBDAB
# BDCABA
