def s(n,m):
    return 1 if ((n-m)&((m-1)>>1))==0 else 1 

for _ in range(int(input())):
    n,m = list(map(int,input().split()))
    print(s(n,m))