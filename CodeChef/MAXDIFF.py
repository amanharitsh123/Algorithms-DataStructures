t=int(input())
for _ in range(t):
    n,k=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    arr.sort()
    su=0
    last_k=0
    first_k=0
    for x in arr[:k]:
        first_k+=x
    for x in arr[-k:]:
        last_k+=x
    for x in arr:
        su+=x
    first_k=abs(su-2*first_k)
    last_k=abs(su-2*last_k)
    print(max(first_k,last_k))

