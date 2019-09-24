from collections import defaultdict
from math import *
from bisect import *
class MajorityChecker:

    def __init__(self, arr):
        
        # Algorithm: (Preprocessing)
        # 1) Make a dictionary that contains elements as key and list of their indices as value.
        # 2) Build segment Tree 
        # TC: O(NlogN)
        self.arr = arr
        self.adj = defaultdict(list) # Adjancy list mapping elements to indices
        for i,x in enumerate(arr):
            self.adj[x].append(i)
        
        # Declaring Tree
        size = 2*(2**(ceil(log2(len(arr)))))-1
        self.tree = [0]*size

        # Lets Create Tree now ! :)
        self.create(0,len(arr)-1,0)
    
    def create(self,i,j,index):
        if i>j:
            return -1
        
        if i==j:
            self.tree[index] = self.arr[i]
            return self.tree[index]
        
        mid = (i+j)//2
        left = self.create(i,mid,2*index+1)
        right = self.create(mid+1,j,2*index+2)
        l,r=bisect_left(self.adj[left],i), bisect_right(self.adj[left],j)
        countleft=r-l
        l,r=bisect_left(self.adj[right],i), bisect_right(self.adj[right],j)
        countright=r-l
        
        if countleft>=countright:
            self.tree[index] = left
        else:
            self.tree[index] = right
        
        return self.tree[index]
    
    def q(self,left,right,i,j,index):
        if i<=left and right<=j:
            return self.tree[index]
        
        if i>right or j<left:
            return -1
        
        mid = (left+right)//2

        l = self.q(left,mid,i,j,2*index+1)
        r = self.q(mid+1,right,i,j,2*index+2)
        x,y=bisect_left(self.adj[l],i), bisect_right(self.adj[l],j)
        countleft=y-x
        x,y=bisect_left(self.adj[r],i), bisect_right(self.adj[r],j)
        countright=y-x
        
        if countleft>=countright:
            return l
        else:
            return r
        



    
    def query(self, left, right, threshold):
        ele = self.q(0,len(self.arr)-1,left,right,0)
        x,y = bisect_left(self.adj[ele],left), bisect_right(self.adj[ele],right)
        
        if y-x >= threshold:
            return ele
        return -1