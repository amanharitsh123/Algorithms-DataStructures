import heapq
class kthLargest:
    def __init__(self,nums,k):
        self.nums=nums
        self.k=k
    
    # Solution Using heap O(nlogk)
    def solve_heap(self):
        arr=self.nums
        k=self.k
        q=[]
        for x in arr:
            if len(q)!=k:
                heapq.heappush(q,x)
            else:
                if q[0]<x:
                    heapq.heappop(q)
                    heapq.heappush(q,x)
        return q[0]
    
    # Solution Using Quick Select Expected TC: O(N)
    def solve_qs(self):
        arr=self.nums
        k=self.k
        start=0
        end=len(arr)-1
        while True:
            pivot=arr[end]
            i=start-1
            j=start
            while j<end:
                if arr[j]<=pivot:
                    i+=1
                    arr[i],arr[j]=arr[j],arr[i]
                j+=1
            pos=i+1
            arr[i+1],arr[end]=arr[end],arr[i+1]
            if len(arr)-pos==k:
                return arr[pos]
            elif len(arr)-pos<k:
                end=pos-1
            else:
                start=pos+1
                
nums=[3,2,1,5,6,4]
k=6
nums=[3,2,3,1,2,4,5,5,6]
k=4
obj=kthLargest(nums,k)
print(obj.solve_qs())
