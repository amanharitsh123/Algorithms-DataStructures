s=input()
onlyone=True
for x in s[1:]:
    if x=="1":
        onlyone=False
ans=(len(s)-1)//2
if not onlyone or (len(s)-1)%2!=0:
    ans+=1
print(ans)