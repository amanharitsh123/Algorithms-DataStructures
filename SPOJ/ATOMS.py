from math import log

for _ in range(int(input())):
    n,k,m = list(map(int,input().split()))
    if m<n:
        print(0)
        continue
    t = log(m/n)
    t = t/log(k)
    print(int(t))