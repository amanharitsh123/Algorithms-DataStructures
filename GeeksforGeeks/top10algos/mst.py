class DSU:
    def __init__(self,n):
        self.n = n
        self.parent = [i for i in range(n+1)]
        self.count = [1 for x in range(n+1)]
    
    def union(self,x,y):
        count = self.count
        parent = self.parent
        px = self.find(x)
        py = self.find(y)
        if count[px]>=count[py]:
            count[px] += count[py]
            parent[py] = px
        else:
            count[py] += count[px]
            parent[px] = py
    
    def find(self,x):
        parent = self.parent
        px = x
        while parent[px] != px:
            px = parent[px]
            parent[px]=parent[parent[px]]
        return px

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        ma = 1
        for x in edges:
            ma = max(ma,max(x))
        s = DSU(ma)
        for x,y in edges:
            if s.find(x)==s.find(y):
                return sorted([x,y])
            # print(s.parent)
            s.union(x,y)
            
        
        