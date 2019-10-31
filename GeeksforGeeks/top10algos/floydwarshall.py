# All pair shortest path
# https://leetcode.com/problems/network-delay-time/
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        N = N + 1
        dist = [[float('inf')]*N for x in range(N)]
        # i----j----k
        # Use path length 
        for i in range(1,N):
            dist[i][i] = 0
            dist[i][0] = 0
            dist[0][i] = 0
        for u,v,d in times:
            dist[u][v] = d
        for k in range(1,N):
            for i in range(1,N):
                for j in range(1,N):
                    if float('inf') in [dist[i][k],dist[k][j]]:
                        continue
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])
        # print(dist)
        dist = dist[K]
        
        return max(dist) if max(dist) != float('inf') else -1