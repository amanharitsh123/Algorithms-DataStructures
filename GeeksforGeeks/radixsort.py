def cs(arr,mul):
    freq=[0]*10
    for x in arr:
        freq[(x/10)%10]+=1
    for x in range(1,10):
        freq[x]+=freq[x-1]
    out=[0]*10
    for x in arr:
        out[]

n=int(input())
arr=list(map(int,input().split()))
mul=1
ma=max(arr)
while ma:
    cs(arr,mul)
    print(" ".join([str(x) for x in arr]))
    mul*=10
# 8
# 170 45 75 90 802 24 2 66