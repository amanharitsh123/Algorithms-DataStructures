for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    dp=[1]*n
    for i in range(1,n):
        for j in range(i):
            if arr[i]>arr[j]:
                dp[i]=max(dp[i],dp[j]+1)
    print(max(dp))
# 2
# 16
# 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
# 6
# 5 8 3 7 9 1