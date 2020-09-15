n=int(input())
k=2
arr=[]
for i in range(1, n):
    val=i**k
    temp=[]
    for j in arr:
        temp.append(j+val)
    for x in temp:
        arr.append(x)
    arr=list(set(arr))
    arr.append(val)
arr=list(set(arr))
arr.sort()
print(len(arr))
#print(arr)
