class node:
    def __init__(self):
        self.isend=False
        self.child=[None]*26

class trie:
    def __init__(self):
        self.head=node()
    
    def insert(self,target):
        temp=self.head
        for i in range(len(target)):
            x=target[i]
            val=ord(x)-ord('a')
            if temp.child[val]==None:
                temp.child[val]=node()
            temp=temp.child[val]
        temp.isend=True
    
    def search(self,target):
        temp=self.head
        for i in range(len(target)):
            x=target[i]
            val=ord(x)-ord('a')
            if temp.child[val]==None:
                return False
            temp=temp.child[val]
        return temp.isend

for _ in range(int(input())):
    n=int(input())
    arr=input().split()
    target=input()
    tree=trie()
    for x in arr:
        tree.insert(x)
    if tree.search(target):
        print(1)
    else:
        print(0)


# 1
# 8
# the a there answer any by bye their
# the
