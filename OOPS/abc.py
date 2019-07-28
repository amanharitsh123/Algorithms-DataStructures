def su(num):
    ans=0
    while num:
        ans+=num%10
        num=num//10
    return ans
for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    ma=-1
    for i in range(n):
        for j in range(i,n):
            ma=max(ma,su(arr[i]*arr[j]))
    print(ma)
# 3
# 2
# 2 8
# 3 
# 8 2 8
# 3
# 9 10 11