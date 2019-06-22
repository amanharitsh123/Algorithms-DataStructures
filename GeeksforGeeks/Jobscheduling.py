for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    mat=[]
    for i in range(0,len(arr),3):
        mat.append((arr[i],arr[i+1],arr[i+2]))
    mat.sort(key=lambda x:x[2],reverse=True)
    slot=[False]*n
    # print(mat)
    # print(min(n-1,mat[0][1]),n)
    slot[min(n-1,mat[0][1]-1)]=True
    ans=mat[0][2]
    count=1
    # Setting job 1st
    # print(mat)
    for x in mat[1:]:
        j=min(n-1,x[1]-1)
        while j>=0:
            if slot[j]==False:
                # print("setting at ",j,x)
                slot[j]=True
                ans+=x[2]
                count+=1
                # print(slot)
                break
            j-=1
    print(count,ans)