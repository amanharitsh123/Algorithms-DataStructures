from math import *
for _ in range(int(input())):
    n,a,k=list(map(int,input().split()))
    # D=A/B
    da=(n-2)*360-2*a*n
    db=n*(n-1)
    A=db*a+(k-1)*da
    B=db
    g=gcd(A,B)
    print(A//g,B//g)