def findpos(n):
    i=0
    dic={}
    while n:
        digit=n%10
        if digit in dic:
            return dic[digit]
        else:
            dic[digit]=i
        i+=1
        n=n//10
    return -1

for _ in range(int(input())):
    start,end=list(map(int,input().split()))
    i=start
    while i<=end:
        pos=findpos(i)
        if pos==-1:
            print(i,end=" ")
            i+=1
        else:
            i=i+(10**pos)-(i%(10**pos))
    print()