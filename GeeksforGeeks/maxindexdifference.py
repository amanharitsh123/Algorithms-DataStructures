# Link: https://practice.geeksforgeeks.org/problems/maximum-index/0
for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    lmin = []
    rmax = []
    ma=float("-inf")
    mi=float("inf")
    
    for i in range(len(arr)-1,-1,-1):
        x=arr[i]
        ma = max(ma,x)
        rmax.append((ma,i))
    i=0
    j=len(arr)-1
    ans=0
    # print(lmin)
    # print(rmax)
    while i<len(arr) and j>=0:
        x=arr[i]
        mi = min(x,mi)
        if mi <= rmax[j][0]:
            ans=max(ans,rmax[j][1]-i)
            j-=1
        else:
            i+=1
    print(ans)


    



# 1
# 9
# 34 8 10 3 2 80 30 33 1