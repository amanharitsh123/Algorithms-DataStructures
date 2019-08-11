from heapq import *
for _ in range(int(input())):
    q=[]
    n=int(input())
    val=list(map(int,input().split()))
    z=list(map(int,input().split()))
    ans=[0]*n
    for i in range(n):
        while len(q) and q[0]<(i):
            heappop(q)
        ans[i]+=len(q)+1
        heappush(q,val[i]+i)
    q=[]
    for i in range(n-1,-1,-1):
        while len(q) and -1*q[0]>(i):
            heappop(q)
        ans[i]+=len(q)
        heappush(q,-1*(i-val[i]))
    # print(ans)
    z.sort()
    ans.sort()
    b=True
    for i in range(n):
        if ans[i]!=z[i]:
            b=False
    if b:
        print("YES")
    else:
        print("NO")





# 2
# 5
# 1 2 3 4 5
# 1 2 3 4 5
# 5
# 1 2 3 4 5
# 5 4 3 4 5