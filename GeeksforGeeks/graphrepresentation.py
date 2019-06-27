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
        pass

    
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