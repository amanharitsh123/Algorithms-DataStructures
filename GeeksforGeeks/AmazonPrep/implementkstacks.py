# Implement K stacks using array
# Use of 3 stacks
# Next : Stores next stack element for each stack element
# Top : top contains index of top element for each stack
class stacks:
    def __init__(self,n,k):
        n=10*n
        self.arr=[-1]*(n)
        self.n=10*n
        self.k=k
        self.Next=[i+1 for i in range(n)]
        self.Next[-1]=-1
        self.Top=[-1]*k
        self.free=0
    
    def push(self,ele,k):
        cur=self.free
        self.free=self.Next[cur]
        self.Next[cur]=self.Top[k]
        self.Top[k]=cur
        self.arr[cur]=ele

    def pop(self,k):
        ele=self.Top[k]
        self.Top[k]=self.Next[ele]
        self.Next[ele]=self.free
        self.free=ele





