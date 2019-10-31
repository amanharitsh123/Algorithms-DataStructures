from math import sqrt
for _ in range(int(input())):
    h,a = list(map(int,input().split()))
    det = h**2 - 16*((a**2)/(h**2))
    if det < 0 :
        print(-1)
        continue
    val = h**2 + h*sqrt(det)
    val = val/2
    val = sqrt(val)
    base = val
    if base == 0:
        print(-1)
        continue
    p = 2*a/base
    ans = sorted([base,p,float(h)])
    for x in ans:
        print ('%.6f'%x,end=" ")
    print() 
