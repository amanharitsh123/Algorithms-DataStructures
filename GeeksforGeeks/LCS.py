for _  in range(int(input())):
    n,m=list(map(int,input().split()))
    s1=input()
    s2=input()
    dp = {}

    # Adding dummy row and dummy column
    for i in range(m+1):
        dp[(0,i)]=0
    
    for i in range(n+1):
        dp[(i,0)]=0
    # print(dp)
    # Solving in Bottom Up fashion
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                dp[(i,j)]=1+dp[(i-1,j-1)]
            else:
                dp[(i,j)]=max(dp[(i-1,j)],dp[(i,j-1)])
    print(dp[(n,m)])

# 2
# 6 6
# ABCDGH
# AEDFHR
# 3 2
# ABC
# AC