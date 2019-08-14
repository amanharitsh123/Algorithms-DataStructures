# Program for nth fibonacci number using fast exponentiation
'''
Basic Formula:
| F[n]   |      | 1  1|**n   | F[n-1] | 
| F[n-1] | =    | 1  0| + | F[n-2] |

'''
# Preprocessing
mod = 10**9 + 7
def matmul(m1,m2):
    a,b,c,d = [x for l in m1 for x in l]
    e,f,g,h = [x for l in m2 for x in l]
    temp=[[a*e+b*g,a*f+b*h],[c*e+d*g,c*f+d*h]]
    for i in range(2):
        for j in range(2):
            temp[i][j]=temp[i][j]%mod
    return temp

default=[[1,1],[1,0]]
dp=[None]*1001
dp[1]=default
for i in range(2,1001):
    if i%2==0:
        dp[i]=matmul(dp[i//2],dp[i//2])
    else:
        dp[i]=matmul(dp[i//2],dp[i//2])
        dp[i]=matmul(dp[i],default)

def solve(n):
    return dp[n]

print(dp)

for _ in range(int(input())):
    n=int(input())-1
    if n==0 or n==1:
        print(1)
        continue
    mat=solve(n-1)
    print((mat[0][0]+mat[0][1])%mod)