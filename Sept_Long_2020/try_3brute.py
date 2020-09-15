k=0
k=int(input())
testcases=int(input())

def small_solve(n, k):
    diff=10000000000000
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

    #print("Mask List is ")
    #for x in mask_list:
        #print(bin(x)[2:])
    pp=bin(ans_max)[2:]
    print("Brute answer")
    print(diff)
    brute=pp[::-1] + '0'*(n-len(pp))
    print(brute)
    return [diff, brute]
    curtotal=total_sum
    opt=['1' for x in range(n)]
    ind=n-1
    while ind>=0:
        if curtotal>=2*(ind+1)**k:
            opt[ind]='0'
            curtotal-=2*(ind+1)**k
        ind-=1
    ind=0
    find_min=curtotal
    min_index=-1
    while ind<n:
        if opt[ind]=='0':
            ind+=1
            continue
        if abs(2*(ind+1)**k - curtotal) < find_min:
            find_min=abs(2*(ind+1)**k-curtotal)
            min_index=ind
        ind+=1
    if min_index!=-1:
        opt[min_index]='0'
    opt="".join(opt)
    print("opt answer")
    print(find_min)
    print(opt)

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

vals=[]
strings=[]
for i in range(1, 27):
    x=small_solve(i, k)
    vals.append(x[0])
    strings.append(x[1])

print(vals)
for x in strings:
    print('"', x, '",', sep="")

while testcases!=0:
    testcases-=1
    solve()

