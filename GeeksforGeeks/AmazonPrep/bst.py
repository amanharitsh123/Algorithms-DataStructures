class node:
    def __init__(self,val):
        self.data=val
        self.right=None
        self.left=None
        self.parent=None

class bst:
    def __init__(self):
        self.root=None
    
    def insert(self,ele):
        if not self.root:
            self.root=node(ele)
        else:
            cur=self.root
            while True:
                if cur.data<ele:
                    if not cur.right:
                        cur.right=node(ele)
                        cur.right.parent=cur
                        break
                    cur=cur.right
                else:
                    if not cur.left:
                        cur.left=node(ele)
                        cur.left.parent=cur
                        break
                    cur=cur.left
    
    def delete(self,ele):
        cur=self.root
        while cur and cur.data != ele:
            if cur.data<=ele:
                cur=cur.left
            else:
                cur=cur.right
        
        if not cur:
            print("Element Not Found!")
            return
        
        while True:
            if not cur.left and not cur.right:
                if cur==cur.parent.left:
                    cur.parent.left=None
                else:
                    cur.parent.right=None
                break
            elif not cur.right:
                if cur==cur.parent.left:
                    cur.parent.left=cur.left
                else:
                    cur.parent.right=cur.left
                break
            elif not cur.left:
                if cur==cur.parent.left:
                    cur.parent.left=cur.right
                else:
                    cur.parent.right=cur.right
                break
            else:
                left=cur.right
                while left.left:
                    left=left.left
                left.data,cur.data=cur.data,left.data
                cur=left

        # Algorithm for this is 
        # Find position for the node then following Cases
        # 1) if its a leaf, delete it simply.
        # 2) if it has one child , swap with that.
        # 3) if both children, find the inorder successor and swap and repeat the process for that node.

