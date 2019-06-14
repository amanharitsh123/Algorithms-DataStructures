class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maximumGap(self, A):
        if len(A)==0:
            return -1
        lis=[]
        for i in range(len(A)):
            lis.append((A[i],i))
        lis.sort(key=lambda x:x[0])
        mi=lis[0][1]
        ans=0
        for x in lis[1:]:
            mi=min(mi,x[1])
            if x[1] -mi >= 0:
                ans=max(ans,x[1]-mi)
        return ans