import math
class Solution:
    # @param A : tuple of integers
    # @return an integer
    def check(self,num,arr,sqrt):
        start=num*sqrt
        end=start+sqrt
        dic={}
        for i in arr:
            if i>=start and i<=end:
                if i in dic:
                    return i
                dic[i]=0
        return -1





    def repeatedNumber(self, A):
        
        # TC: O(N) SC: O(N)
        dic={}
        for i in A:
            if i in dic:
                return i
            else:
                dic[i]=0
        return -1

        # Approach provided in editoral but incorrect
        # target_numbers = int(math.ceil(math.sqrt(len(A))))
        # count = [0]*target_numbers
        # print("targt",target_numbers)
        # for i in A:
        #     ind=i//target_numbers
        #     count[ind]+=1
        
        # for i in range(len(count)):
        #     if count[i] < target_numbers or count[i] > target_numbers:
        #         ans = self.check(i,A,target_numbers)
        #         if ans !=-1:
        #             return ans
        # return -1


