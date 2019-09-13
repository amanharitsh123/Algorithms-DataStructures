class Solution:
    # @param A : tuple of integers
    # @return an integer
    def count_sort(self,i,A):
        dic={}
        for x in A:
            num=x
            temp=-1
            digit=-1
            while temp+1!=i:
                x=x//10
                temp+=1
            digit=x%10
            if digit in dic:
                dic[digit].append(num)
            else:
                dic[digit]=[num]
        ans=[]
        for i in range(10):
            if i in dic:
                ans+=dic[i]
        return ans
    
    def maximumGap(self, A):
        # Solution Using Count Sort
        # arr=list(A)
        
        # for x in range(11):
        #     arr=self.count_sort(x,arr)
        # # print(arr==sorted(list(A)))
        # ma=0
        # for i in range(1,len(arr)):
        #     ma=max(arr[i]-arr[i-1],ma)
        # return ma
        
        # Pigeonhole sorting
        # A=list(A)
        mi=10000000000000
        ma=-1
        for x in A:
            mi=min(x,mi)
            ma=max(ma,x)
        n=len(A)
        if n==1:
            return 0
        gap=(ma-mi)/(n-1)
        if ma==mi:
            return 0 
        max_array=[0]*(n)
        min_array=[10000000000]*(n)
        
        # Filling Pigeonholes
        for x in range(len(A)):
            
            # Find Index of the bucket
            # print(n-1,gap)
            index = int((A[x]-mi)//gap)
            # print(index,n-1,gap)
            max_array[index]=max(max_array[index],A[x])
            min_array[index]=min(min_array[index],A[x])
        ans=0
        # print(max_array)
        # print(min_array)
        prev=0
        for i in range(1,n):
            if max_array[i] != 0 and min_array[prev] !=  10000000000000:
                ans=max(ans,min_array[i]-max_array[prev])
                prev=i
        return ans     

        
