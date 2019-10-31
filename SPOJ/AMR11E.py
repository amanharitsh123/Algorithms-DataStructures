lucky = []
factors = [0]*(10000)
def sieve():
    for x in range(2,10000):
        step = x
        if factors[x] == 0:
            while x < 10000:
                factors[x] += 1
                x += step
        
        if factors[step] >= 3:
            lucky.append(x)

sieve()
for _ in range(int(input())):
    t = int(input())
    print(lucky[t-1])

# 2
# 1
# 2