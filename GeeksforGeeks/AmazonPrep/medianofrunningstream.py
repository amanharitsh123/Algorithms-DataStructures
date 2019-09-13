# Median of number in a running stream
# Brute Force : O(n^2) by inserting element in a sorted array 
# Optimized : O(nlogn) using heaps
#!/bin/python3

import os
import sys
import heapq

#
# Complete the runningMedian function below.
#
def runningMedian(a):
    ma=[]
    mi=[]
    a=[float(x) for x in a]
    ans=[]
    for x in a:
        if len(mi)==len(ma):
            heapq.heappush(ma,-1*x)
        else:
            if len(mi)>len(ma):
                heapq.heappush(ma,-1*x)
            else:
                heapq.heappush(mi,x)
        while len(ma) and len(mi) and abs(ma[0]) > abs(mi[0]):
            e1,e2=heapq.heappop(ma),heapq.heappop(mi)
            e1,e2=abs(e1),abs(e2)
            heapq.heappush(mi,e1)
            heapq.heappush(ma,-1*e2)
        
        if len(mi)==len(ma):
            ans.append((abs(ma[0])+abs(mi[0]))/2)
        else:
            ans.append(-1*ma[0] if len(ma)>len(mi) else mi[0])
    return ans

            
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input())

    a = []

    for _ in range(a_count):
        a_item = int(input())
        a.append(a_item)

    result = runningMedian(a)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
