# LCS can be used to solve this problem 
# Find the LCS and solve according to following two cases to get
# Diff like output
# 1) if character x, present in st1 and absent in lcs append -x.
# 2) if character x, present in st2 and absent in lcs append +x.

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

print("Enter strings ")
s1=input()
s2=input()
n=len(s1)
m=len(s2)
# Solve for lcs length
# Bottom UP
dp=[[0]*(m+1) for x in range(n+1)]

for i in range(1,n+1):
    for j in range(1,m+1):
        if s1[i-1]==s2[j-1]:
            dp[i][j]=1+dp[i-1][j-1]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])

# Getting LCS string using lcs array
st=[]
printlcs(n,m,st) # Print One LCS
st.reverse()
i=0
j=0
x=0
ans=""
while x<len(st) and (i<len(s1) or j<len(s2)):
    if i<len(s1):
        if s1[i]!=st[x]:
            ans+="-"+s1[i]
            i+=1
    if j<len(s2):
        if s2[j]!=st[x]:
            ans+="+"+s2[j]
            j+=1
    if i<len(s1) and j<len(s2):
        if s1[i]==s2[j] and s1[i]==st[x]:
            ans+=s1[i]
            x+=1
            i+=1
            j+=1
    elif j<len(s2):
        if s2[j]==st[x]:
            ans+=s2[j]
            x+=1
            j+=1
    elif i<len(s1):
        if s1[i]==st[x]:
            ans+=s1[i]
            x+=1
            i+=1
print(ans)

# XMJYAUZ
# XMJAATZ
