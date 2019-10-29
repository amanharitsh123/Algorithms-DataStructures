from math import ceil, gcd
while True:
    n,k = list(map(int,input().split()))
    if n == -1 and k == -1:
        exit()
    total = (n*(n-1))
    even = k//2
    odds = int(ceil(k/2))
    s_even = even*(even-1)
    s_odd = odds*(odds-1)
    optimal = s_even + s_odd
    g = gcd(optimal,total)
    if optimal==0 or (optimal==total):
        print(optimal//total)
        continue
    optimal = optimal//g
    total = total//g
    print("{}/{}".format(optimal,total))





# Input:
# 3 2
# 100 5
# 10 6
# -1 -1

# Output:
# 0
# 2/2475
# 2/15