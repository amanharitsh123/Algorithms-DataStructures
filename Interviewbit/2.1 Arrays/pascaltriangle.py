class Solution:
    # @param A : integer
    # @return a list of list of integers
    def solve(self, A):
        if A==0:
            return []
        ans=[[1]]
        for n in range(2,A+1):
            lis=[0]*n
            lis[0]=1
            lis[-1]=1
            for i in range(1,n-1):
                lis[i]=ans[-1][i-1]+ans[-1][i]
            ans.append(lis)
        return ans