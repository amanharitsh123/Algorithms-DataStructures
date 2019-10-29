class Solution:
    # @param A : integer
    # @return a list of integers
    def ncr(self,n,r):
        if r==0 or n==r:
            return 1
        top=1
        down=1
        for i in range(r+1,n+1):
            top=top*i
            down=down*(i-r)
        return top/down

    def getRow(self, A):
        ans=[]
        n=A
        for i in range(n+1):
            ans.append(self.ncr(n,i))
        return ans
