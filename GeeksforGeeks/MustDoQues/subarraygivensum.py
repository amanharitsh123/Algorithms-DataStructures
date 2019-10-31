for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    dic={}
    su=0
    dic[0]=-1
    arr=list(map(int,input().split()))
    start,end=-1,-1
    for i in range(n):
        su+=arr[i]
        if su-k in dic:
            start=dic[su-k]+1
            end=i
            break
        dic[su]=i
    if start==-1 and end==-1:
        print(-1)
    else:
        print(start+1,end+1)
    




# 2
# 5 12
# 1 2 3 7 5
# 10 15
# 1 2 3 4 5 6 7 8 9 10