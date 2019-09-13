# Longest Palindromic Subsequence
# Submitted on leetcode
def solve(s,i,j,dp):
    if (i,j) in dp:
        return dp[(i,j)]
    
    if i>j:
        return 0
    
    if s[i]==s[j]:
        dp[(i,j)]=1+solve(s,i+1,j-1,dp)
        if i!=j: # if the matched character is different from the current character itself
            dp[(i,j)]+=1
    else:
        dp[(i,j)]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp))
    
    return dp[(i,j)]

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:

        # Top Down
        dp={}
        # ans=solve(s,0,len(s)-1,dp)

        # Bottom UP DP
        n=len(s)
        dp=[[1]*n for i in range(n)]
        ans=1

        for i in range(2,n+1):
            for j in range(n-i+1):
                x=j
                y=j+i-1
                if s[x]==s[y]:
                    if i==2:
                        dp[x][y]=2
                        continue
                    dp[x][y]=2+dp[x+1][y-1]
                    ans=max(ans,dp[x][y])
                else:
                    dp[x][y]=max(dp[x][y-1],dp[x+1][y])
        # print(dp)
        return dp[0][n-1]