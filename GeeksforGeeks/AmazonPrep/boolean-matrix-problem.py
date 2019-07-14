for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    mat=[]
    for i in range(n):
        mat.append(list(map(int,input().split())))
        
    for i in range(1,n):
        for j in range(1,m):
            if mat[i][j]==1:
                mat[i][0]=1
                mat[0][j]=1
    
    
    for i in range(1,n):
        for j in range(1,m):
            if mat[i][0] or mat[0][j]:
                mat[i][j]=1
    
    if mat[0][0]==1:
        for i in range(n):
            mat[i][0]=1
        for j in range(m):
            mat[0][j]=1
    
    for i in range(n):
        for j in range(m):
            print(mat[i][j],end=" ")
        print()
    





# 3
# 2 2
# 1 0 
# 0 0
# 2 3
# 0 0 0 
# 0 0 1
# 4 3
# 1 0 0
# 1 0 0
# 1 0 0
# 0 0 0