from heapq import *
from sys import stdin, stdout
k=int(stdin.readline())
testcases=int(stdin.readline())
def compli(x):
    return '1' if x=='0' else '0'

def solve():
    n=int(stdin.readline())
    ans=['0' for _ in range(n)]
    q=[]
    # {val, type, I1, T1, I2, T2}
    arr=[]
    difflist=[]
    for i in range(0, n-2):
        arr.append([-(i+1)**k, 1, i, '0'])
    #print('q size is', len(q))
    difflist=[[-(2*n-1), 2, n-1, '1', n-2, '0']]
    last_n=-1
    for i in range(n-2, 0, -2):
        curdiff=1-2*i
        if (i-1)**k < abs(difflist[0][0]):
            break
        last_n=i
        difflist.append([curdiff, 2, i, '1', i-1, '0'])
    for x in arr[:i-1]:
        heappush(q, x)
    for x in difflist:
        heappush(q, x)
    print(len(q))
    while len(q)!=1:
        top1=heappop(q)
        top2=heappop(q)
        val=abs(top1[0])-abs(top2[0])
        if top2[1]==1 and top1[1]==1:
            # both elements , assig greater one to 1
            ans[top1[2]]='1'
            heappush(q, [-val, 2, top1[2], '1', top2[2], '0'])
        elif top1[1]==2 and top2[1]==2:
            ans[top2[2]]=top1[5]
            ans[top2[4]]=top1[3]
            top1[0]=-val
            heappush(q, top1)
        elif top2[1]==2:
            #print('type is ', top2[1], top1[1], top2[0], top1[0])
            #print(top2[4])
            #print(top1[3])
            ans[top2[4]]=top1[3];
            ans[top2[2]]=compli(top1[3])
            top1[0]=-val
            heappush(q, top1)
        else:
            #print('here')
            ans[top2[2]]=top1[5]
            top1[0]=-val
            heappush(q, top1)
    stdout.write(str(abs(heappop(q)[0])))
    stdout.write('\n')
    #print(ans)
    stdout.write("".join(ans)+'\n')
for _ in range(testcases):
    solve()


