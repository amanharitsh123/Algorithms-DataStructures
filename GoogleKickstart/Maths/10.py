limit = 2000000
prime = [True]*(10**7)
ans = 0
# ans = []
for x in range(2,limit):
    if prime[x]:
        step = x
        x += step
        while x<limit:
            prime[x] = False
            x += step
        ans += step
print(ans)
