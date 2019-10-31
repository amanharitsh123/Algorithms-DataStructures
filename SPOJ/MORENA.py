n=int(input())
arr = list(map(int,input().split()))

# Using DP would be an overkill and result in TLE O(N^2) = O(10^6^2) = O(10^12) :/ TLE
# O(N) Solution
# Algo:
# 1) Make another array of 0 and 1
# 2) arr[i] = 0 if arr[i] < arr[i-1] elif arr[i] > arr[i-1] 1 , in case of dups mark previously assigned value

temp = [0]*n
prev = 0
for i in range(1,n):
    if arr[i]>arr[i-1]:
        temp[i] = 1
        prev = 1
    elif arr[i]<arr[i-1]:
        temp[i] = 0
        prev = 0
    else:
        temp[i] = prev

count = 1
if arr[0] > arr[1]:
    temp[0] = 1 
for i in range(1,n):
    if temp[i] != temp[i-1]:
        count += 1
        prev = temp[i]
print(count) 


# print(temp)

# 8
# 1 4 2 10 1 9 7 8