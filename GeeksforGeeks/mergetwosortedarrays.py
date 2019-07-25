for _ in range(int(input())):
    i=0
    j=0
    n1,n2=list(map(int,input().split()))
    a1=list(map(int,input().split()))
    a2=list(map(int,input().split()))
    while i+j != n1:
        if i>=n1:
            j+=1
            continue
        if j>=n2:
            i+=1
            continue
        if a1[i]>=a2[j]:
            j+=1
        else:
            i+=1
    
    if n1>=n2:
        y=0
        while i<n1:
            a1[i],a2[y]=a2[y],a1[i]
            i+=1
            y+=1
    elif n2>n1:
        x=0
        while j<n2:
            a2[j],a1[x]=a1[x],a2[j]
            j+=1
            x+=1
    a1.sort()
    a2.sort()
    if a1[0]<a2[0]:
        for x in a1:
            print(x,end=" ")
        for x in a2:
            print(x,end=" ")
    else:
        for x in a2:
            print(x,end=" ")
        for x in a1:
            print(x,end=" ")
    print()
            
        