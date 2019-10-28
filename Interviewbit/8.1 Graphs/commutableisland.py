import heapq
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
            return 
        
        self.distinct_sets-=1
        if size[px] > size[py]:
            sets[py]=px
            size[px]+=size[py]
        else:
            sets[px]=py
            size[py]+=size[px]
    
    def find(self,x):
        sets=self.sets
        while sets[x]!=x:
            sets[x]=sets[sets[x]]
    
            x=sets[x]
        return x

class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    
    # Kruskal's algorithm
    # def solve(self, A, B):
    #     s=Dset(A+1)
    #     B.sort(key=lambda x:x[2])
    #     ans=0
    #     for x in B:
    #         if s.find(x[0])!=s.find(x[1]):
    #             ans+=x[2]
    #             s.union(x[0],x[1])
    #     return ans
    
    # Prim's Algorithm
    def solve(self, A, B):
        q=[(0,1)]
        heapq.heapify(q)
        visited = [False for x in range(A+1)]
        ans=0
        adj = [[]for x in range(A+1)]
        for x in B:
            adj[x[0]].append((x[1],x[2]))
            adj[x[1]].append((x[0],x[2]))
        ans=0
        while len(q):
            # prin/t(q)
            ele=heapq.heappop(q)
            if not visited[ele[1]]:
                visited[ele[1]]=True
                ans+=ele[0]
                for x in adj[ele[1]]:
                    heapq.heappush(q,(x[1],x[0]))
        return ans
                
                
                
                
                
            
        
        
