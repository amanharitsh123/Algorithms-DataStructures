for _ in range(int(input())):
    n,k = list(map(int,input().split()))
    arr = list(map(int,list(input())))
    right = [0]*(n+1)
    count = 0
    for i in range(n-1,-1,-1):
        if arr[i]==1:
            count += 1
        else:
            count = 0
        right[i] = count
    count = 0
    ans = 0
    for i in range(n):
        length = 0
        length = count + (min(i+k,n)-i) + right[min(i+k,n)]
        ans = max(ans,length)
        if arr[i] == 1:
            count += 1
        else:
            count = 0
    print(ans)

# 2
# 13 2
# 0101110000101
# 6 3
# 100001