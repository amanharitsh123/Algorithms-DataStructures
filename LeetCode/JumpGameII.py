class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        ans=0
        while i < len(nums)-1:
            ind = -1
            ma = 0
            offset=1
            while offset <= nums[i]:
                if offset+i >=len(nums)-1:
                    return ans+1
                if (ma < nums[offset+i]+offset+i) and nums[offset+i]!=0:
                    ind=offset+i
                    ma=nums[offset+i]+offset+i
                offset+=1
            i=ind
            ans+=1
        return ans
                    
                
                
        
        
        