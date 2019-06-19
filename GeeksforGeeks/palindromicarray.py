for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    start=0
    end=len(arr)-1
    ans=0
    while start < end:
        if arr[start]==arr[end]:
            start+=1
            end-=1
        elif arr[start]>arr[end]:
            ans+=1
            arr[end-1]+=arr[end]
            end-=1
        else:
            ans+=1
            arr[start+1]+=arr[start]
            start+=1
    print(ans)