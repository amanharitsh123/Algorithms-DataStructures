for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    dic={}
    for x in arr:
        dic[x]=1
    ans=0
    for i in range(n):
        for j in range(i+1,n):
            if arr[i]+arr[j] in dic:
                ans+=1
    print(ans if ans!=0 else -1)