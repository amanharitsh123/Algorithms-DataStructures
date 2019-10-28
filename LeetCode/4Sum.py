# Find all unique quads that sums to target. TC:O(N^3) SC:O(N^2)
def solve(nums,i,j,t):
    target=t-nums[i]-nums[j]
    start=j+1
    end=len(nums)-1
    ans=[]
    arr=nums
    while start<end:
        if start==i or start==j:
            start+=1
        elif end==j or end==i:
            end-=1
        elif arr[start]+arr[end]==target:
            ans.append(tuple(sorted([arr[start],arr[end],arr[i],arr[j]])))
            start+=1
            end-=1
            # Skipping redundant pairs 
            while start<end and arr[start]==arr[start-1] and arr[end]==arr[end+1]:
                start+=1
                end-=1
        elif arr[start]+arr[end]<target:
            start+=1
        else:
            end-=1
    return ans

def bs(arr,aux,target,x,y):
    i=0
    j=len(aux)-1
    ans=[]
    while i<j:
        mid=(i+j)//2
        if aux[mid][2]==target:
            tup=aux[mid]
            left=mid
            right=mid+1
            while left>=0 and aux[left][2]==target:
                tup=aux[left]
                if tup[0] in (x,y) or tup[1] in (x,y):
                    left-=1
                    continue
                ans.append((arr[x],arr[y],arr[tup[0]],arr[tup[1]]))
                left-=1
            
            while right<len(aux) and aux[right][2]==target:
                tup=aux[right]
                if tup[0] in (x,y) or tup[1] in (x,y):
                    right+=1
                    continue
                # print("appending",x,y,tup[0],tup[1])
                ans.append((arr[x],arr[y],arr[tup[0]],arr[tup[1]]))
                right+=1
            break
        elif aux[mid][2]>target:
            j=mid-1
        else:
            i=mid+1
    return ans
# Optimizing the solution by storing all the possible sum of pairs and applying binary search

def solve_opt(arr,target):
    aux=[]
    n=len(arr)
    # Creating pairs aux array
    dic={}
    for i in range(n):
        for j in range(i+1,n):
            x=arr[i]
            y=arr[j]
            # x,y=max(x,y),min(x,y)
            # print("appedning ",i,j)
            temp=(i,j,x+y)
            if temp not in dic:
                aux.append(temp)
                dic[temp]=1
    aux.sort(key=lambda x:x[2])
    i=0
    ans=[]
    # print(len(aux))
    # print(aux)
    while i<n:
        j=i+1
        while j<n:
            t=target-arr[i]-arr[j]
            temp=bs(arr,aux,t,i,j)
            # temp=solve(nums,i,j,target)
            ans.extend(x for x in temp)
            j+=1
            # skipping same elements 
            while j<n and arr[j]==arr[j-1]:
                j+=1
        i+=1
        # skipping same elements 
        while i<n and arr[i]==arr[i-1]:
            i+=1
    return list(set(tuple(sorted(x)) for x in ans))

    




class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        return solve_opt(nums,target)
        # n=len(nums)
        # nums.sort()
        # ans=[]
        # i=0
        # while i<n:
        #     j=i+1
        #     while j<n:
        #         temp=solve(nums,i,j,target)
        #         ans.extend(x for x in temp)
        #         j+=1
        #         # skipping same elements 
        #         while j<n and nums[j]==nums[j-1]:
        #             j+=1
        #     i+=1
        #     # skipping same elements 
        #     while i<n and nums[i]==nums[i-1]:
        #         i+=1
        # return ans