def solve(start,end):
    if (start,end) in dp:
        return dp[(start,end)]
    if start==end:
        return arr[start]
    if start>end:
        return 0
    x=arr[start]+min(solve(start+2,end),solve(start+1,end-1))
    y=arr[end]+min(solve(start,end-2),solve(start+1,end-1))
    dp[(start,end)]=max(x,y)
    return max(x,y)
    
    
for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    start=0
    end=len(arr)-1
    dp={}
    print(solve(start,end))