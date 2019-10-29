class Solution:
    # @param A : list of integers
    # @return an integer
    def maxArr(self, A):
        # bruteforce O(n^2)
        # expand modulo
        val_plus_min=10000000000000000
        val_plus_max=-10000000000000000
        val_minus_max=-10000000000000000
        val_minus_min=1000000000000000
        for i in range(len(A)):
            val_plus_max=max(val_plus_max,A[i]+i+1)
            val_plus_min=min(val_plus_min,A[i]+i+1)
            val_minus_max=max(val_minus_max,A[i]-i-1)
            val_minus_min=min(val_minus_min,A[i]-i-1)

        # checking 4 cases
        # print(val_minus_max,val_minus_min,val_plus_max,val_plus_min)
        ans=0
        ans=max(ans,val_plus_max-val_plus_min)
        ans=max(ans,val_minus_max-val_minus_min)
        ans=max(ans,-val_plus_max+val_plus_min)
        ans=max(ans,-val_minus_max+val_minus_min)
        return ans
