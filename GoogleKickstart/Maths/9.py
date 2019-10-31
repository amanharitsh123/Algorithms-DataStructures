ans = -1
for a in range(1,1001):
    for b in range(1,1001):
        c = 1000-a-b
        if c<0:
            continue
        if a**2+b**2 == c**2:
            ans = a*b*c
print(ans)