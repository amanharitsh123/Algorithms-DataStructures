def qsort(arr,i,j):
    if i>=j:
        return 
    # Partition
    pivot=arr[j]
    x=i-1
    t=i
    while t<=j:
        if arr[t]<=pivot:
            x+=1
            arr[x],arr[t]=arr[t],arr[x]
        t+=1
    arr[x+1]=pivot
    qsort(arr,i,x)
    qsort(arr,x+2,j)

    
n=int(input())
arr=list(map(int,input().split()))
qsort(arr,0,n-1)