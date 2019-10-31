n,m = list(map(int,input().split()))
rows = list(map(int,input().split()))
cols = list(map(int,input().split()))
mat = [[0]*m for _ in range(n)]

for i in range(len(rows)):
    vals = rows[i]+1
    j = 0
    while j<m and vals:
        mat[i][j] = 1
        vals -= 1
        j+=1
for i in range(len(cols)):
    vals = cols[i]+1
    j = 0
    while j<n and vals:
        mat[j][i] = 1
        vals -= 1
        j += 1
print(mat)




# 3 4
# 0 3 1
# 0 2 3 0