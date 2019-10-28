
# O(N^2K) / O(NK)
def maxProfit(self, k: int, prices: List[int]) -> int:
        K=k
        n=len(prices)
        arr=prices
        if not len(arr):
            return 0
        dp=[[0]*(K+1) for i in range(n+1)]
        # n=0 k=0 profit 0
        ans=0
        for i in range(2,n+1):
            for k in range(1,K+1):
                for x in range(i-1,0,-1):
                    if arr[i-1]>arr[x-1]:
                        dp[i][k]=max(dp[i][k],dp[x-1][k-1]+arr[i-1]-arr[x-1])
                dp[i][k]=max(dp[i][k],dp[i-1][k])
                ans=max(ans,dp[i][k])
        # print(dp[6])
        # print(dp[4])
        return ans

# O(NK) / O(NK)
def maxProfit(self, k: int, prices: List[int]) -> int:
        # global dp
        # dp={}
        # return self.solve(0,k,prices)
        K=k
        n=len(prices)
        arr=prices
        if not len(arr):
            return 0
        dp=[[0]*(K+1) for i in range(n+1)]
        # n=0 k=0 profit 0
        ans=0
        for k in range(1,K+1):
            prevdiff=float("-inf")
            for i in range(2,n+1):
                dp[i][k]=arr[i-1]+max(prevdiff,dp[i-1][k-1]-arr[i-2])
                prevdiff=max(prevdiff,dp[i-1][k-1]-arr[i-2])
                dp[i][k]=max(dp[i][k],dp[i-1][k])
        # print(dp[6])
        # print(dp[4])
        return dp[n][K]
        # return ans

# O(NK) / O(N)


for _ in range(int(input())):
    # O(N^3) 
    K=int(input())
    n=int(input())
    arr=list(map(int,input().split()))
    dp=[[0]*(K+1) for i in range(n+1)]
    # n=0 k=0 profit 0
    ans=-1
    for i in range(2,n+1):
        prevdiff=float("-inf")
        for k in range(1,K+1):
            dp[i][k]=arr[i]+max(prevdiff,dp[i-1][k-1]-arr[i-1])
            prevdiff=max(prevdiff,dp[i-1][k-1]-arr[i-1])
            dp[i][k]=max(dp[i][k],dp[i-1][k])
    # print(dp[6])
    # print(dp[4])
    print(ans)