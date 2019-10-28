for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    i=1
    ans=0
    for x in arr:
        ans=ans^x
        ans=ans^i
        i+=1
    print(ans^i)
        