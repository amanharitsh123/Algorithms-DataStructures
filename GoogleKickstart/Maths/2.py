l1 = 1
l2 = 2
ans = 0
lim = 4000000 
while l2 <= lim:
    if l2%2 == 0:
        ans += l2
    l2,l1 = l1+l2,l2
print(ans)

