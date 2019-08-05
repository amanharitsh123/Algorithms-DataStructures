import queue
def valid(blocked,x,y):
    n=10**6
    m=10**6
    if x>=0 and x < n and y>=0 and y<m:
        return True
    return False

class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        offset=[(0,1),(1,0),(-1,0),(0,-1)]
        q1=queue.Queue()
        q1.put(tuple(source))
        visited1={}
        b1={}
        for x in blocked:
            b1[tuple(x)]=1
        blocked=b1
        if len(blocked)<=1:
            return True
        visited2={}
        q2=queue.Queue()
        q2.put(tuple(target))
        while q.qsize():
            top1=q1.get()
            x1=top1[0]
            y1=top1[1]
            visited1[top1]=1
            top2=q2.get()
            x2=top2[0]
            y2=top2[1]
            visited2[top2]=1
            if list(top1)==target:
                return True
            if list(top2)==source:
                return True
            
            
            
            visited[top]=1
            for i,j in offset:
                if valid(blocked,x+i,y+j) and (x+i,y+j) not in visited:
                    q.put((x+i,y+j))
        return False
            
