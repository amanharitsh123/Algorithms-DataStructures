'''
There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.

A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.

Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.

'''


class Solution:
    def solve(self,arr,i,j,dp,su,k):
        print(i,j)
        n=j-i+1
        x=n%k
        y=n//k
        if n==1 or x==0:
            return su[(i,j)]
        if (x+y)%k !=0:
            return float("inf")
        ans=float("inf")
        for x in range(i,j-k+1):
            if k==2:
                ans=min(ans,0+self.solve(arr,i,x,dp,su,k)+self.solve(arr,i,x+1,dp,su,k)+ su[(i,j)])
            else:
                ans=min(ans,su[(x+1,x+k-2)]+self.solve(arr,i,x,dp,su,k)+self.solve(arr,x+k-1,j,dp,su,k)+su[(i,x)]+su[(i,j)])
        print(i,j,ans)
        return ans
    
    
    def mergeStones(self, stones: List[int], K: int) -> int:
        # Check if possible
        n=len(stones)
        k=K
        x=n%k
        y=n//k
        if (x+y)%k !=0:
            return -1
        dp={}
        su={}
        sum=[0]*n
        for i in range(n):
            if i==0:
                sum[i]=stones[i]
            else:
                sum[i]=sum[i-1]+stones[i]
        for i in range(n):
            for j in range(i,n):
                su[(i,j)]=sum[j]-sum[i]+stones[i]
                su[(j,i)]=0
        return self.solve(stones,0,n-1,dp,su,k)