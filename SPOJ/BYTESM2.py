for _ in range(int(input())):
    r,c=list(map(int,input().split()))
    mat=[]
    for i in range(r):
        mat.append(list(map(int,input().split())))
    dp=[x for x in mat[-1]]
    for i in range(r-2,-1,-1):
        ans=[0]*c
        for j in range(c):
            ans[j]=mat[i][j]+dp[j]
            if j-1 >=0:
                ans[j]=max(ans[j],dp[j-1]+mat[i][j-1])
            if j+1<c:
                ans[j]=max(ans[j],dp[j+1]+mat[i][j+1])
        dp=ans
    print(max(dp))
            
            

# 1
# 6 5
# 3 1 7 4 2
# 2 1 3 1 1
# 1 2 2 1 8
# 2 2 1 5 3
# 2 1 4 4 4
# 5 2 7 5 1