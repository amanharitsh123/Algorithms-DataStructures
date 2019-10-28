for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    ans=float("-inf")
    su=0
    for x in arr:
        su+=x
        ans=max(ans,su)
        if su<0:
            su=0
    print(ans)
# 2
# 5
# 1 2 3 -2 5
# 4
# -1 -2 -3 -4