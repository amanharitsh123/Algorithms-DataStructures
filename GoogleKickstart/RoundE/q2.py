prefix_eating=[0]*(100001)
suffix_coding=[0]*(100001)
from bisect import *
# Utility Function for bruteforce
def single_check(val,tc,sc):
    tc=max(tc,0)
    sc=max(sc,0)
    c1,s1=val
    f=tc/c1
    if f>1:
        return False
    ss1=(1-f)*s1
    if ss1>=sc:
        return True
    return False

# BruteForce solution(for Test Set #1) 
def solve(tc,sc):
    c1,s1=values[0]
    # For one slot
    if len(values)==1:
        return single_check(values[0],tc,sc)

    # For two slots
    for cc1 in range(c1+1):
        f=cc1/c1
        ss1=(1-f)*s1
        if single_check(values[1],tc-cc1,sc-ss1):
            return True
    return False
            
def solve_optimized():
    values.sort(key=lambda x:x[2])
    slots=s
    prefix_eating[0]=values[0][1]
    suffix_coding[slots-1]=values[-1][0]
    # Making prefix and sufix sum arrays
    for i in range(1,slots):
        prefix_eating[i]=values[i][1]+prefix_eating[i-1]
        end=slots-1-i
        suffix_coding[end]=values[end][0]+suffix_coding[end+1]
    # print(prefix_eating)
    # print(suffix_coding)
    for _ in range(d):
        tc,te=input().split()
        tc=int(tc)
        te=int(te)
        ind=bisect_left(prefix_eating,te,0,slots)
        # Find residue coding that can be obtained from above slot
        verdict=True
        ind=min(ind,slots-1)
        extra_eating=prefix_eating[ind]-te
        if extra_eating>0:
            f=(values[ind][1]-extra_eating)/values[ind][1]
            tc=tc-(1-f)*values[ind][0]
            tc=max(tc,0)
        if ind+1>=slots:
            if tc!=0 or prefix_eating[slots-1]<te:
                verdict=False
        else:
            if suffix_coding[ind+1]<tc:
                verdict=False

        if verdict:
            print("Y",end="")
        else:
            print("N",end="")
    



for t in range(int(input())):
    d,s=input().split()
    d=int(d)
    s=int(s)
    values=[]
    for _ in range(s):
        ci,ei=input().split()
        ci=int(ci)
        ei=int(ei)
        values.append((ci,ei,ci/ei))
    print("Case #{}: ".format(t+1),end="")
    solve_optimized()
    print()
    # for x in range(d):
    #     tc,sc=list(map(int,input().split()))
    #     if solve(tc,sc):
    #         ans.append("Y")
    #     else:
    #         ans.append("N")
    

# 2
# 4 2
# 3 8
# 6 10
# 0 18
# 3 13
# 10 0
# 7 3
# 1 2
# 4 4
# 4 4
# 0 0
