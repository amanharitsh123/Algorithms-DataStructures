limit = 10**7
prime = [True]*(10**7)
ans = []
ans = []
for x in range(2,limit):
    if prime[x]:
        step = x
        x += step
        while x<limit:
            prime[x] = False
            x += step
        ans.append(step)
print(ans[10000])
