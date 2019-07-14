class Graph:
    def __init__(self,V):
        self.V=V
        self.E=0
        self.nodes=[[] for x in range(V+1)]
    
    # Directed Edges
    def addedge(self,x,y):
        self.E+=1
        self.nodes[x].append(y)
    
    # Topological sort if the graph is a DAG(Directed Acyclic Graph)
    def topo_sort(self):
        stack = []
        visited = [False for x in range(self.V+1)]
        for x in range(1,self.V+1):
            if not visited[x]:
                self.topo_util(x,stack,visited)
        return stack

    def topo_util(self,source,stack,visited):
        if not visited[source]:
            visited[source]=True
            for x in self.nodes[source]:
                self.topo_util(x,stack,visited)
            stack.append(source)
    
    def ssc_dfs(self,source,visited):
        num=0
        if not visited[source]:
            num=1
            visited[source]=True
            for x in self.nodes[source]:
                num+=self.ssc_dfs(x,visited)
        return num


    def ssc(self):
        # returing (C,D)
        # Where C Sum of number of nodes in all Strongly Connected Components with odd number of nodes.
        # D Sum of number of nodes in all Strongly Connected Components with even number of nodes.
        st=self.topo_sort()
        visited = [False for x in range(self.V+1)]
        even=0
        odd=0
        for x in st:
            temp=self.ssc_dfs(x,visited)
            if temp%2==0:
                even+=temp
            else:
                odd+=temp
        return odd-even

n,m = list(map(int,input().split()))
graph=Graph(n)
for i in range(m):
    a,b = list(map(int,input().split()))
    graph.addedge(a,b)

print(graph.ssc())





# 5 6
# 1 4
# 1 3
# 2 4
# 3 4
# 4 5
# 5 1