import heapq
# from itertools import groupby

for _ in range(int(input())):
    st=input()
    k=int(input())
    dic={}
    for x in st:
        if x in dic:
            dic[x]+=1
        else:
            dic[x]=1
    q=[]
    for x in dic:
        q.append(-1*dic[x])
    # q=[-1*len(list(group)) for key, group in groupby(a)]
    ans=0
    heapq.heapify(q)
    while k:
        top=heapq.heappop(q)
        # print(top)
        if top==0:
            break
        top+=1
        k-=1
        heapq.heappush(q,top)
    while q:
        top=heapq.heappop(q)
        ans=ans+(top**2)
    print(ans)