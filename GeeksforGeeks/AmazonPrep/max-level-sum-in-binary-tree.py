'''
class Node:
    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None
'''
import queue
def maxLevelSum(root):
    # Code here
    q=queue.Queue()
    q.put((root))
    ans=float("-inf")
    q.put("n")
    t=0
    while q.qsize():
        x=q.get()
        if x=="n":
            if q.qsize():
                q.put(x)
            ans=max(ans,t)
            t=0
        else:
            t+=x.data
            if x.left:
                q.put(x.left)
            if x.right:
                q.put(x.right)
    return ans
