s1=""
s2=""
dp=[]
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

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        # Find lcs first
        n=len(str1)
        m=len(str2)
        global s1,s2,dp
        s1=str1
        s2=str2
        dp=[[0]*(m+1) for x in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,m+1):
                if s1[i-1]==s2[j-1]:
                    dp[i][j]=1+dp[i-1][j-1]
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        st=[]
        printlcs(n,m,st)
        st.reverse()
        ans=[]
        st.append("*") # To handle the case when there is no LCS
        i=0
        j=0
        x=0
        while i<len(s1) or j<len(s2):
            if i<len(s1) and s1[i]!=st[x]:
                ans.append(s1[i])
                i+=1
                continue
            if j<len(s2) and s2[j]!=st[x]:
                ans.append(s2[j])
                j+=1
                continue
            first=""
            if i<len(s1):
                first=s1[i]
            second=""
            if j<len(s2):  # first string fully processed only second string remaining
                second=s2[j]
            if first=="":
                first=st[x] 
            if second=="": # Second string fully processed
                second=st[x]
            if first==second and first==st[x]:
                ans.append(st[x])
                i+=1
                j+=1
                x+=1
        return "".join(ans)
                    
            
            