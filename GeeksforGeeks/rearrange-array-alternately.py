def half(arr,i):
    if i<len(arr)//2:
        return True
    return False

for _ in range(int(input())):
    n=int(input())
    arr=input().split()
    for i in range(n):
        arr[i]=int(arr[i])
    for i in range(n):
        if arr[i] >0:
            target=i
            val=arr[i]
            pval=arr[i]
            x=i
            while True:
                if half(arr,x):
                    next=2*x+1
                else:
                    next=n-1-x
                    next=next*2
                # print(next)
                t=arr[next]
                if t<0:
                	break
                arr[next]=-1*pval
                pval=t
                x=next
                if x==target:
                    break
    arr=list(map(abs,arr))
    for x in arr:
        print(x,end=" ")
    print()