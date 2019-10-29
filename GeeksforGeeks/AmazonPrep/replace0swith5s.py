def convertFive(n):
    #Code here
    t=n
    count=0
    while t:
        dig=t%10
        if dig==0:
            n+=5*(10**count)
        t=t//10
        count+=1
    return n