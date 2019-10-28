# Activity Selection Problem
for _ in range(int(input())):
    n=int(input())
    start=list(map(int,input().split()))
    end=list(map(int,input().split()))
    matrix=[]
    i=0
    for x,y in zip(start,end):
        matrix.append((x,y,i))
        i+=1
    matrix.sort(key=lambda x:x[1])
    prev=matrix[0]
    print(prev[2]+1,end=" ")
    
    for x in matrix[1:]:
        if x[0] >= prev[1]:
            prev=x
            print(prev[2]+1,end=" ")
    print()