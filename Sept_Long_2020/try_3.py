k=0
k=int(input())
testcases=int(input())

def small_solve(n, k):
    diff=1000000000000000
    ans_max=-1
    total_sum=0
    for i in range(1, n+1):
        total_sum+=i**k
    
    mask_list=[]
    for mask in range(2**n):
        cursum=0
        for i in range(n):
            if mask & 1<<i:
                cursum+=(i+1)**k
        vv=abs(total_sum-2*cursum)
        if vv < diff:
            diff=abs(total_sum-2*cursum)
            #if diff==0:
                #print(bin(mask))
                #return
            ans_max=mask
            mask_list=[]
            mask_list.append(mask)
        elif vv==diff:
            mask_list.append(mask)

    print("Mask List is ")
    for x in mask_list:
        print(bin(x)[2:])
    pp=bin(ans_max)[2:]
    print("Brute answer")
    print(diff)
    brute=pp[::-1] + '0'*(n-len(pp))
    print(brute)

def solve():
    n=int(input())
    su=0
    small_solve(n, k);
    return
    for i in range(1, n):
        su+=i**4
        if su>(i+1)**4:
            print(i)
    print(n**4-su)

while testcases!=0:
    testcases-=1
    solve()

