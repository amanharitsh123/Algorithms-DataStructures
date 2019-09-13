# https://codeforces.com/contest/1208/problem/B
n=int(input())
arr=list(map(int,input().split()))
dic={}
for x in arr:
    if x not in dic:
        dic[x]=1
    else:
        dic[x]+=1
aux=[0]*len(arr)
start=0
end=len(arr)-1

