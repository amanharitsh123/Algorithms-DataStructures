from heapq import *
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # Base Case
        # if k==0:
        #     return 0
        # # DP states: k,w,index
        # dp=[[0]*(len(Profits)+1) for x in range(k+1)]
        # max_till_now=W
        # temp=[]
        # for i in range(len(Profits)):
        #     temp.append((Capital[i],Profits[i]))
        # temp.sort(key=lambda x:x[0])
        # for i in range(len(Profits)):
        #     Capital[i],Profits[i]=temp[i]
        # # Base case of k=1
        # for i in range(1,len(Profits)+1):
        #     if Capital[i-1]<=W:
        #         max_till_now=max(max_till_now,W+Profits[i-1])
        #     dp[1][i]=max_till_now
        # K=k
        
        # for k in range(2,K+1):
        #     for i in range(1,len(Profits)+1):
        #         cap=dp[k-1][i-1]
        #         if Capital[i-1]<=cap:
        #             dp[k][i]=max(dp[k][i-1],cap+Profits[i-1],dp[k-1][i])
        #         else:
        #             dp[k][i]=max(dp[k][i-1],dp[k-1][i],cap)
                
        # # print(min(K,len(Profits)))
        # return dp[min(K,len(Profits))][len(Profits)]
        # Solution using heap
        combined=sorted(zip(Capital,Profits))
        i=0
        q=[]
        ans=W
        for _ in range(k):
            while i<len(combined) and combined[i][0]<=ans:
                heappush(q,-1*combined[i][1])
                i+=1
            if not q:
                return ans
            t=heappop(q)
            ans+=-t
        return ans


