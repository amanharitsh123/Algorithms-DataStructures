class Solution:
    # @param A : list of integers
    # @return a list of integers
    def maxset(self, A):
        max_sum=0
        temp_sum=0
        start=-1
        end=-1
        i=0
        start_temp=0
        while i<len(A):
            if A[i]<0:
                start_temp=i+1
                temp_sum=0
            else:
                temp_sum+=A[i]
                if temp_sum>max_sum or (temp_sum==max_sum and i-start_temp > end-start):
                    max_sum=temp_sum
                    start=start_temp
                    end=i
            i+=1
        if start==-1:
            return []
        return A[start:end+1]
                    
