for _ in range(int(input())):
    arr=list(input())
    dic={}
    ans=True
    for x in range(len(arr)):
        # print(arr[x])
        ele=arr[x]
        if ele.isnumeric():
            # print("here")
            j=x
            tele=int(ele)+1
            while j>=0 and tele:
                if j in dic:
                    ans=False
                    break
                dic[j]=1
                # print("added ",j)
                j-=1
                tele-=1
            
            j=x+1
            tele=int(ele)
            while j<len(arr) and tele:
                if j in dic:
                    ans=False
                    break
                # print("added ",j)
                dic[j]=1
                j+=1
                tele-=1
        # print(dic)
        if not ans:
            break
    if ans:
        print("safe")
    else:
        print("unsafe")






# 4
# ....
# .2.....
# .2...2..
# 1.1.1.