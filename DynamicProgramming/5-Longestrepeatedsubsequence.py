# Find the length of longest common subsequence
# Submitted on geeksforgeeks
def printlcs(i,j,st):
    if i==0 or j==0:
        return 
    if s1[i-1]==s2[j-1] and i!=j:
        st.append(s1[i-1])
        printlcs(i-1,j-1,st)
    else:
        if dp[i-1][j] >= dp[i][j-1]:
            printlcs(i-1,j,st)
        else:
            printlcs(i,j-1,st)

for _ in range(int(input())):
    n=int(input())
    s1=input()
    s2=s1
    # Top Down
    # Same as lcs but ignore same indices
    # Bottom UP
    dp=[[0]*(n+1) for x in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            if s1[i-1]==s2[j-1] and i!=j:
                dp[i][j]=1+dp[i-1][j-1]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    print(dp[n][n])
    st=[]
    printlcs(n,n,st)
    print("".join(st[::-1]))
    


# 2
# 3
# abc
# 5
# axxxy