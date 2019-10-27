while True:
    n = float(input())
    if n==0:
        exit()
    i = 2
    val = 0
    card = 0
    while val <= n:
        card += 1
        val += (1/i)
        i += 1
    print(card,end=" ")
    print("card(s)")

# 1.00
# 3.71
# 0.04
# 5.19
# 0.00