for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    arr.sort()
    j=len(arr)-1
    count=0
    while j>=2:
        start=0
        end=j-1
        target=arr[j]
        while start<end:
            if arr[start]+arr[end]>arr[j]:
                end-=1
            elif arr[start]+arr[end]<arr[j]:
                start+=1
            else:
                count+=1
                start+=1
                end-=1
        j-=1
    if count==0:
        print(-1)
    else:
        print(count)