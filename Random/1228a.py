l,r = list(map(int,input().split()))
for x in range(l,r+1):
    t = list(str(x))
    if len(t) == len(list(set(t))):
        print(x)
        exit()
print(-1)