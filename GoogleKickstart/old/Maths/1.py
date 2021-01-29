i = 1
j = 1
ans = 0
while i*3 < 1000 or 5*j < 1000:
    t = min(3*i,5*j)
    ans += t
    print('Counted ',t)
    if t == 3*i:
        i += 1
    if t == 5*j:
        j += 1
print(ans)
