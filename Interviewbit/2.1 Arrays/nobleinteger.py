class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        A.sort()
        i=0
        while i<len(A):
            if A[i]==len(A)-i-1:
                return 1
            i+=1
            while i+1<len(A) and A[i]==A[i+1]:
                i+=1
        return -1
