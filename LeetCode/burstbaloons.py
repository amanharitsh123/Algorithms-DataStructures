class Solution(object):
    def solve(self,nums,i,j,dp):
        if (i,j) in dp:
            return dp[(i,j)]
        ans=-1
        if i==j:
            return nums[i]*nums[i-1]*nums[i+1]
        if i>j:
            return 0
        for k in range(i,j+1):
            ans=max(ans,self.solve(nums,i,k-1,dp)+self.solve(nums,k+1,j,dp)+nums[i-1]*nums[j+1]*nums[k])
        dp[(i,j)]=ans
        return ans
    
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        dp={}
        return self.solve(nums,1,len(nums)-2,dp)