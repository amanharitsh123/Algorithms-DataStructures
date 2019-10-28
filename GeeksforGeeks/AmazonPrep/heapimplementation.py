import math
# Heap implementation from scratch
# min heapify and max heapify
def minhpfy(arr,i):
    left=2*i+1
    right=2*i+2
    mi=arr[i]
    if left<last:
        mi=min(mi,arr[left])
    if right<last:
        mi=min(mi,arr[right])
    if left<last:
        if mi==arr[left]:
            arr[left],arr[i]=arr[i],arr[left]
            minhpfy(arr,left)
            return
    if right<last:
        if mi==arr[right]:
            arr[right],arr[i]=arr[i],arr[right]
            minhpfy(arr,right)

arr=[5,2,3,1]
last=len(arr)
n=math.ceil(math.log2(len(arr)))-1
print(2**(n) )
for i in range(2**(n)  ,-1,-1):
    minhpfy(arr,i)
    # print(arr)
for i in range(last):
    print(arr[0])
    arr[0],arr[last-1]=arr[last-1],arr[0]
    arr[last-1]=float("inf")
    minhpfy(arr,0)
    # print(arr)
    last-=1