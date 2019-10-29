def bsearch(arr,target):
    start=0
    end=len(arr)-1
    while start<end:
        mid = (start+end)//2
        if arr[mid]==target:
            return mid
        if arr[mid]<target:
            start=mid+1
        else:
            end=mid-1
    return start
for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    ax=list(map(int,input().split()))
    ay=list(map(int,input().split()))
    ax.sort()
    ay.sort()
    count=0
    for y in ay:
        print(y,bsearch(ax,y))
        count+=n-bsearch(ax,y)
    print(count)

# 1
# 3 2
# 2 1 6
# 1 5