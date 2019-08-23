from bisect import *

class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        ans=0
        dic={}
        for x in D:
            if x in dic:
                dic[x]+=1
            else:
                dic[x]=1
        aux=[]
        for i in range(len(C)):
            for j in range(len(D)):
                aux.append(C[i]+D[j])
        aux.sort()
        for i in range(len(A)):
            for j in range(len(B)):
                t=A[i]+B[j]
                t=-1*t
                start=0
                end=len(aux)-1
                count=0
                # Find Lowerbound
                lower=bisect_left(aux,t)
                higher=bisect_right(aux,t)
                # print(t,count)
                ans+=higher-lower
        return ans
        