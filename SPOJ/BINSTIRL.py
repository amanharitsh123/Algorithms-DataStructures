def s(n,m):
    if n==0 and m==0:
        return 1
    if n==0 or m==0:
        return 0
    return m*s(n-1,m) + s(n-1,m-1)
for x in range(10):
    for y in range(10):
        print(x,y,"ans = ",s(x,y)%2)
