def solve(st,i,ans):
    if i==len(st)-1:
        ans.append(st[i])
        print("("+"".join(ans)+")",end="")
        ans.pop(-1)
        return 
    ans.append(st[i]+" ")
    solve(st,i+1,ans)
    ans.pop(-1)
    ans.append(st[i])
    solve(st,i+1,ans)
    ans.pop(-1)

for _ in range(int(input())):
    st=input()
    solve(st,0,[])



# Input:
# 2
# AB
# ABC

# Output:
# (A B)(AB)
# (A B C)(A BC)(AB C)(ABC)