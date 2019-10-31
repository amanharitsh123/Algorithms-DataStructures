from math import sqrt

lim = 10**8
num = 0
val = 1
ma = 0
def solve(num):
    factors = 0
    for x in range(1,int(sqrt(num))):
        if num%x == 0:
            factors += 1
            if num//x != x:
                factors += 1
    return factors



while num+val<lim:
    num += val
    val += 1
    if solve(num) > 500:
        print(num)
        exit()
print(ma)

# 76576500