import functools
class Solution:
    # @param A : tuple of integers
    # @return a strings
    def compare(self,x,y):
        x,y=x+y,y+x
        # print(x,y)
        if x<y:
            return 1
        if y<x:
            return -1
        return 0
    def largestNumber(self, A):
        li=[]
        for i in range(len(A)):
            li.append(str(A[i]))
        li=sorted(li,key=functools.cmp_to_key(self.compare))
        return int("".join(li))
