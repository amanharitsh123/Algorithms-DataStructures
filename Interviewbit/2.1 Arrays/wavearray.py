class Solution:
    # @param A : list of integers
    # @return a list of integers
    def wave(self, A):
        A.sort()
        i=0
        while i<len(A)-1:
            A[i+1],A[i]=A[i],A[i+1]
            i+=2
        return A