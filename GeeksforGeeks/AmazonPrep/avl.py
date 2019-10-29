class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
        self.height=0

class avl:
    def __init__(self):
        self.root=None
    
    def insertutil(self,root,data):
        if data<=root.data:
            if root.left:
                self.insertutil(root.left,data)
            else:
                root.left=node(data)
            h=root.left.height
            if root.right:
                h=max(h,root.right.height)
            root.height=1+h
        else:
            if root.right:
                self.insertutil(root.right,data)
            else:
                root.right=node(data)
            h=root.right.height
            if root.left:
                h=max(h,root.left.height)
            root.height=1+h

    def insert(self,x):
        # First Node of the Tree
        if not self.root:
            self.root=node(x)
            return
        self.insertutil(self.root,x)
    
    def preorderutil(self,root):
        if not root:
            return
        print(root.data)
        self.preorderutil(root.left)
        self.preorderutil(root.right)
        
    def preorder(self,x):
        cur=self.root
        while cur.data!=x:
            if x<cur.data:
                cur=cur.left
            else:
                cur=cur.right
        self.preorderutil(cur)

n=int(input())
arr=list(map(int,input().split()))
tree=avl()
for x in arr:
    tree.insert(x)
t=int(input())
tree.preorder(t)