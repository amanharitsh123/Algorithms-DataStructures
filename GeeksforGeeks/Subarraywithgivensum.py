for _ in range(int(input())):
    n,target=list(map(int,input().split()))
    arr=list(map(int,input().split()))
    i=0
    j=-1
    su=0
    done=False
    while True:
        while su>target and i<=j:
            su-=arr[i]
            i+=1
        if su==target:
            print(i+1,j+1)
            done=True
            break
        j+=1
        if j>=len(arr):
            break
        su+=arr[j]
    
    if not done and su!=target:
        print(-1)
    if su==target and not done:
        print(i+1,max(i+1,j))
            



# 2
# 5 12
# 1 2 3 7 5
# 10 15
# 1 2 3 4 5 6 7 8 9 10