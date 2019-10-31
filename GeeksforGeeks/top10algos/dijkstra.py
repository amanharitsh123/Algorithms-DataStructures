# https://leetcode.com/problems/network-delay-time/
from collections import defaultdict
from heapq import *
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        # (u,v,w)
        adj = defaultdict(list)
        dist = [float('inf')]*(N+1)
        dist[0] = 0
        for u,v,w in times:
            adj[u].append((v,w))
        q = []
        dist[K] = 0
        heappush(q,(0,K))
        while q:
            d,u = heappop(q)
            dist[u] = min(d,dist[u])
            for x,w in adj[u]:
                if d+w<dist[x]:
                    heappush(q,(d+w,x))
        return max(dist) if max(dist) != float('inf') else -1