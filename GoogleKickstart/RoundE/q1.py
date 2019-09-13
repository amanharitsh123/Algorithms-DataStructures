# Using Union-Find with path compression and Union by rank
class Dset:
    def __init__(self,n):
        self.sets=[i for i in range(n)]
        self.distinct_sets=n
        self.size=[1 for i in range(n)]
    
    def union(self,x,y):
        size=self.size
        sets=self.sets
        px=self.find(x)
        py=self.find(y)
        if px==py:
            return 0
        
        self.distinct_sets-=1
        if size[px] > size[py]:
            sets[py]=px
            size[px]+=size[py]
        else:
            sets[px]=py
            size[py]+=size[px]
        return 1
    
    def find(self,x):
        sets=self.sets
        while sets[x]!=x:
            sets[x]=sets[sets[x]]
    
            x=sets[x]
        return x

for t in range(int(input())):
    n,m=list(map(int,input().split()))
    s=Dset(n+1)
    ans=0
    for __ in range(m):
        a,b=list(map(int,input().split()))
        ans+=s.union(a,b)
    dis=s.distinct_sets
    dis-=2
    ans+=dis*2
    print("Case #{}: {}".format(t+1,ans))
