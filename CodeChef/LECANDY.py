for _ in range(int(input())):
    n,c=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    su=0
    for x in arr:
        su+=x
    if su<=c:
        print("Yes")
    else:
        print("No")