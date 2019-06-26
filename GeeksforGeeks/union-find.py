# Basic method using Arrays 
# Union_naive,TC: O(N)
# find_naive,TC: O(1)

# Example : [0,1,2,3,4,5] -> Union_naive(0,3) -> [0,1,2,0,4,5]
def Union_naive(x,y):
    # decrement distinct set counts
    if find_naive(x,y):
        return 
    global distinct_sets
    distinct_sets-=1
    temp=sets[y]
    for i in range(n):
        if sets[i]==temp:
            sets[i]=sets[x]

def find_naive(x,y):
    return sets[x]==sets[y]


# Tree method using arrays
# Union TC: O(log(N))
# find TC: O(long(N))

def Union(x,y):
    px=find(x)
    py=find(y)
    if px==py:
        return 
    global distinct_sets
    distinct_sets-=1
    if size[px] > size[py]:
        sets[py]=px
        size[px]+=size[py]
    else:
        sets[px]=py
        size[py]+=size[px]
# find with path compression 
def find(x):
    while sets[x]!=x:
        if x==9:
            print("here",sets[x],sets[sets[x]])
        sets[x]=sets[sets[x]]

        x=sets[x]
    return x
    
    
# Driver Code
n=10
# Mapping of trees
sets=[i for i in range(n)]
# Size of each tree
size=[1 for i in range(n)]
# Number of disjoint sets
distinct_sets=n
Union(1,2)
Union(2,3)
Union(2,3)
Union(5,6)
Union(6,7)
Union(8,9)
Union(6,8)
print(sets,size)
# Testing Path Compression
find(8)
print(sets)
print(distinct_sets)
