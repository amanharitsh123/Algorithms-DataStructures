class Solution:
    # @param A : string
    # @return a list of integers
    def flip(self, A):
        num_one=0
        num_zero=0
        ans=0
        x=-1
        y=-1
        start=0
        i=0
        while i<len(A):
            if A[i]=="1":
                num_one+=1
            else:
                num_zero+=1
            if num_zero - num_one > ans:
                ans=num_zero - num_one
                x=start
                y=i
            else:
                while num_zero < num_one and start<=i:
                    if A[start]=="1":
                        num_one-=1
                    else:
                        num_zero-=1
                    start+=1
            i+=1
        if x!=-1:
            return [x+1,y+1]
        else:
            return []