import queue
# Graph Representation using adjancy list
# V node and E edges
class Graph:
    def __init__(self,V):
        self.V=V
        self.E=0
        self.nodes=[[] for x in range(V+1)]
    
    def addedge(self,x,y):
        self.E+=1
        self.nodes[x].append(y)
    
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
                
    def dfs(self,source):
        visited = [False for x in range(self.V+1)]
        ans=[]
        self.dfs_util(source,visited,ans)
        return ans

    def printlist(self):
        print(self.nodes)

# Driver function
graph=Graph(10)

graph.addedge(1,2)
graph.addedge(2,3)
graph.addedge(4,3)
graph.addedge(5,6)
graph.addedge(7,8)
graph.addedge(1,10)
graph.printlist()
print(graph.bfs(1))
print(graph.dfs(1))