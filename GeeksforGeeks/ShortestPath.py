import queue,heapq
# Graph Representation using adjancy list
# V node and E edges
class Graph:
    def __init__(self,V):
        self.V=V
        self.E=0
        self.nodes=[[] for x in range(V+1)]
    
    # Directed Edges
    def addedge(self,x,y):
        self.E+=1
        self.nodes[x].append((y,1))
    
    # Breadth First Search
    def bfs(self,source):
        visited = [False for x in range(self.V + 1)]
        ans = []
        q = queue.Queue()
        q.put(source)
        ans = []
        while q.qsize() >0:
            top=q.get()
            if not visited[top]:
                for x in self.nodes[top]:
                    if not visited[x]:
                        q.put(x)
                visited[top]=True
                ans.append(top)
        return ans
    
    
    def dfs_util(self,source,visited,ans):
        if not visited[source]:
            visited[source]=True
            ans.append(source)
            for x in self.nodes[source]:
                self.dfs_util(x,visited,ans)
    
    # Depth First Search            
    def dfs(self,source):
        visited = [False for x in range(self.V+1)]
        ans=[]
        self.dfs_util(source,visited,ans)
        return ans
    
    # Topological sort if the graph is a DAG(Directed Acyclic Graph)
    def topo_sort(self):
        stack = []
        visited = [False for x in range(self.V+1)]
        for x in range(1,self.V+1):
            if not visited[x]:
                self.topo_util(x,stack,visited)
        return " ".join(stack[::-1])

    def topo_util(self,source,stack,visited):
        if not visited[source]:
            visited[source]=True
            for x in self.nodes[source]:
                self.topo_util(x,stack,visited)
            stack.append(str(source))
    
    def cycle_util(self,source,stack,visited):
        if not visited[source]:
            visited[source]=True
            for x in self.nodes[source]:
                if x in stack:
                    return True
                else:
                    stack.append(x)
                    return self.cycle_util(x,stack,visited)
        return False


    # Cycle Detction in Directed Graph
    def iscycle(self):
        visited = [False for x in range(self.V+1)]
        for x in range(1,self.V+1):
            if not visited[x] and self.cycle_util(x,[x],visited):
                return True
        return False
    
    def shotest_path(self,source):
        q=[(0,source)]
        dist=[float("inf") for x in range(self.V+1)]
        dist[source]=0
        finalized=[False for x in range(self.V+1)]
        while len(q):
            top=heapq.heappop(q)
            if not finalized[top[1]]:
                weight=top[0]
                vert=top[1]
                for x in self.nodes[vert]:
                    if dist[x[0]]>weight+x[1]:
                        dist[x[0]]=weight+x[1]
                        heapq.heappush(q,(dist[x[0]],x[0]))
                finalized[vert]=True
        return dist
graph=Graph(10)
graph.addedge(1,2)
graph.addedge(2,3)
graph.addedge(3,4)
graph.addedge(4,5)
graph.addedge(5,6)
graph.addedge(6,7)
graph.addedge(7,8)
graph.addedge(1,10)
graph.addedge(8,1)
print(graph.shotest_path(1))