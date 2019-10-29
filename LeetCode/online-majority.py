from collections import defaultdict
from copy import copy
from bisect import *
# O(N^2) Solution
class MajorityChecker:

    def __init__(self, arr: List[int]):
        dic=defaultdict(int)
        self.dic_arr=[defaultdict(int)]
        for x in  arr:
            dic[x]+=1
            self.dic_arr.append(copy(defaultdict))
        
    def query(self, left: int, right: int, threshold: int) -> int:
        hi=copy(self.dic_arr[right])
        lo=copy(self.dic_arr[left-1])
        ma=-1
        ele=-1
        for x in hi:
            hi[x]=hi[x]-lo[x]
            if hi[x]>ma:
                ma=hi[x]
                ele=x
        if ma>=threshold:
            return ele

# Solution Binary Seach
class MajorityChecker:

    def __init__(self, arr: List[int]):
        
        # Algorithm: (Preprocessing)
        # 1) Make a dictionary that contains elements as key and list of their indices as value.
        # 2) Make a list of elements that as sorted according to frequency of each element. 
        # TC: O(NlogN)
        self.arr=arr
        self.doi=defaultdict(list)
        for i,x in enumerate(arr):
            self.doi[x].append(i)
        self.majorityelements = sorted(self.doi.keys(),key = lambda x:len(self.doi[x]))
    
    def query(self, left: int, right: int, threshold: int) -> int:
        # Algo:
        # 1) Traverse each majorityelements list and pick each element one by one.
        # 2) For each element, Binary search on its list of indices. Find indices such that l>=left and r<=right.
        # 3) check if r-l>=threshold
        for ele in self.majorityelements:
            if len(self.doi[ele])<threshold:
                return -1

            l,r=bisect_left(self.doi[ele],left), bisect_right(self.doi[ele],right)

            if r-l+1>=threshold:
                return ele



        

        


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
