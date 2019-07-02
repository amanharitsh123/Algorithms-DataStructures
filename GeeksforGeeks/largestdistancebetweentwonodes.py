import sys
sys.setrecursionlimit(5000)
 
import heapq
class Solution:
    # @param A : list of integers
    # @return an integer
    # recursive approach
    def sol(self,root,dic):
        if len(dic[root])==0:
            return (0,0)
        if len(dic[root])==1:
            t=self.sol(dic[root][0],dic)
            return (max(t[0],t[1]+1),t[1]+1)
        q=[]
        for x in dic[root]:
            t=self.sol(x,dic)
            heapq.heappush(q,t)
            if len(q)>2:
                heapq.heappop(q)
        
        # Returning (maxinmychild,maxheight)
        return (max(q[0][0],q[1][0],q[1][1]+q[0][1]+2),1+max(q[1][1],q[0][1]))
    
    # Iterative approach
    def sol_iterative(self,A):
        ans=[]
        for i in range(len(A)):
            ans.append([0,0])
        for i in range(len(A)):
            if A[i]!=-1:
                edges=1
                t=A[i]
                while t != -1:
                    # print(t)
                    heapq.heappush(ans[t],edges)
                    if len(ans[t])>2:
                        heapq.heappop(ans[t])
                    t=A[t]
                    edges+=1
        ma=-1
        for i in ans:
            ma=max(ma,i[0]+i[1])
        return ma
    def solve(self, A):
        root=-1
        dic={}
        for i in range(len(A)):
            if i not in dic:
                dic[i]=[]
            if A[i]==-1:
                root=i
                dic[root]=[]
            else:
                if A[i] in dic:
                    dic[A[i]].append(i)
                else:
                    dic[A[i]]=[i]
        ans = self.sol(root,dic)
        # return self.sol_iterative(A)
        