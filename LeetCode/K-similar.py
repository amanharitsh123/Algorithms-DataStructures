visited={}
def solve(i,a,b):
    # print("".join(a),"".join(b))
    s1="".join(a)
    s2="".join(a)
    n=len(a)
    if (s1,s2) in visited:
        # print("hit")
        return visited[(s1,s2)]
    if i>=len(a):
        return 0
    ans=float("inf")
    
    if a[i]==b[i]:
        visited[(s1,s2)]=solve(i+1,a,b)
        return visited[(s1,s2)]
    else:
        x=i+1
        while x<n:
            if b[x]==a[i]:
                b[x],b[i]=b[i],b[x]
                ans=min(ans,1+solve(i+1,a,b))
                b[x],b[i]=b[i],b[x]
        visited[(s1,s2)]=ans
    return ans


import collections
class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        # Brute Force Solution: Use recursion TC:(N^N)
        dic=collections.defaultdict(list)
        for i,ele in enumerate(B):
            dic[ele].append(i)
        return solve(0,0,list(A),list(B),dic)