class Solution:
    # @param A : integer
    # @return a list of list of integers
    def generateMatrix(self, A):
        i=1
        n=A
        matrix=[[0]*n for x in range(n)]
        x,y=0,0
        for n in range(A,0,-2):
            # Left
            for t in range(n):
                matrix[x][y]=i
                i+=1
                y+=1
            y-=1
            x+=1
            
            # Down
            for t in range(1,n):
                matrix[x][y]=i
                i+=1
                x+=1
            x-=1
            y-=1
            
            #Right
            for t in range(1,n):
                matrix[x][y]=i
                i+=1
                y-=1
            x-=1
            y+=1
                
            #UP
            for t in range(2,n):
                matrix[x][y]=i
                i+=1
                x-=1
            x+=1
            y+=1
        return matrix
            
            
