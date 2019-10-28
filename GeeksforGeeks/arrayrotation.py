# Rotation Using Judgling Algorithm
# TC: O(N)
# SC: O(1)
import math
for _ in range(int(input())):
    n,d = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    for i in range(math.gcd(n,d)):
        temp=arr[i]
        j=i
        while (i+d)%n != j:
            arr[i]=arr[(i+d)%n]
            i=(i+d)%n
        arr[i]=temp
    print(" ".join([str(x) for x in arr]))