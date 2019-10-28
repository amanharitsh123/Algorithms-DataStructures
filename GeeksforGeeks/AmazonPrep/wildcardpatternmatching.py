dp={}
def match(s,p,i,j):
    if (i,j) in dp:
        return dp[(i,j)]
    if i>=len(s) and j>=len(p):
        return True
    if j>=len(p):
        return False
    if i>=len(s):
        if p[j]=="*":
            return match(s,p,i,j+1)
        else:
            return False
    if s[i]==p[j]:
        dp[(i,j)]= match(s,p,i+1,j+1)
    elif p[j]=='?':
        dp[(i,j)]= match(s,p,i+1,j+1)
    elif p[j]=="*":
        dp[(i,j)]= match(s,p,i+1,j+1) or match(s,p,i+1,j) or match(s,p,i,j+1)
    else:
        dp[(i,j)]= False
    return dp[(i,j)]
        
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # global dp
        # dp={}
        # Top Down DP
        # return match(s,p,0,0)
        # Bottom UP DP
        s="X"+s
        p="X"+p
        n=max(len(s),len(p))
        dp=[[False]*n for x in range(n)]
        dp[0][0]=True
        j=1
        while j<len(p) and p[j]=="*":
            dp[0][j]=True
            j+=1
        for i in range(1,n):
            for j in range(1,n):
                # if i==j:
                #     continue
                if i>=len(s) and j>=len(p):
                    dp[i][j]=dp[i-1][j-1]
                elif i>=len(s):
                    if p[j]=="*":
                        dp[i][j]=dp[i][j-1]
                elif j>=len(p):
                    dp[i][j]=False
                else:
                    if s[i]==p[j] or p[j]=="?":
                        dp[i][j]=dp[i-1][j-1]
                    elif p[j]=="*":
                        # print("here",i,j)
                        dp[i][j]=dp[i-1][j-1] or dp[i-1][j] or dp[i][j-1]
        return dp[len(s)-1][len(p)-1]