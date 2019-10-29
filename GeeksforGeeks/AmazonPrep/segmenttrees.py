from math import *
# Segment tree class with rmq , range sum and lazy propagation.
# TC: O(N) Tree Construction O(log n) Query and O(log n) Update.(Without Lazy)
class segmenttrees:
    def __init__(self,arr):
        self.arr=arr
        n=len(arr)
        n=int(ceil(log2(n)))
        self.size_st=2*2**n-1  # Size of Segmenet tree
        self.tree=[0]*self.size_st # Declaring tree
        self.constructtree() # Function to construct  tree
    
    def constructtree(self):
        self.constutil(0,len(self.arr)-1,0)
    
    def constutil(self,i,j,ind):
        if i>j:
            return 0
        
        if i==j:
            self.tree[ind]=self.arr[i]
            return self.arr[i]

        left=2*ind+1
        right=2*ind+2
        mid=(i+j)//2
        self.tree[ind]=min(self.constutil(i,mid,left),self.constutil(mid+1,j,right))
        return self.tree[ind]
    
    def query(self,i,j):
        return self.queryutil(i,j,0,len(self.arr)-1,0)
    
    def update(self,i,val):
        self.updateutil(i-1,val,0,len(self.arr)-1,0)
    
    def updateutil(self,i,val,x,y,ind):
        if x>i or y<i:
            return
        if x==y and x==i:
            self.tree[ind]=val
        else:
            left=2*ind+1
            right=2*ind+2
            mid=(x+y)//2
            self.updateutil(i,val,x,mid,left)
            self.updateutil(i,val,mid+1,y,right)
            self.tree[ind]=min(self.tree[left],self.tree[right])
        
    def queryutil(self,x,y,i,j,ind):
        if x<=i and y>=j:
            return self.tree[ind]

        if j<x or i>y or i>j:
            return float("inf")
        
        left=2*ind+1
        right=2*ind+2
        mid=(i+j)//2
        return min(self.queryutil(x,y,i,mid,left),self.queryutil(x,y,mid+1,j,right))

n,q=list(map(int,input().split()))
arr=list(map(int,input().split()))
tree=segmenttrees(arr)
for _ in range(q):
    inp=input().split()
    if inp[0]=='q':
        inp=[int(x) for x in inp[1:]]
        print(tree.query(inp[0]-1,inp[1]-1))
    else:
        inp=[int(x) for x in inp[1:]]
        tree.update(inp[0],inp[1])