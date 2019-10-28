class Solution:
    # @param A : list of list of integers
    # @return a list of list of integers
    def traverse(self,A,x,y):
        lis=[]
        while y>=0 and x<len(A[0]):
            lis.append(A[x][y])
            y-=1
            x+=1
        return lis

    def diagonal(self, A):
        if len(A)==0:
            return []
        ans=[]
        # Left
        x=0
        y=0
        while y<len(A[0]):
            ans.append(self.traverse(A,x,y))
            y+=1
        # Down
        y-=1
        x+=1
        while x<len(A[0]):
            ans.append(self.traverse(A,x,y))
            x+=1
        return ans
                

