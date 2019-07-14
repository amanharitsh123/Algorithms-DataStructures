import heapq
# Input: nums = [1,1,1,2,2,3], k = 2  
# Output: [1,2]
# Complexity must be better than nlogn
class Solution(object):
    def topKFrequent(self, nums, k):
        # Brute force : make array of pairs like (count,element) and sort . get last k pairs for answer
        # Efficient : use of heap to get k most frequent elements O(nlogk)
        dic={}
        for x in nums:
            if  x not in dic:
                dic[x]=1
            else:
                dic[x]+=1
        # Heap 
        q=[]
        for x in dic:
            heapq.heappush(q,(dic[x],x))
            if len(q) > k:
                heapq.heappop(q)
        ans=[]
        while len(q):
            ans.append(heapq.heappop(q)[1])
        return ans
        
        

        