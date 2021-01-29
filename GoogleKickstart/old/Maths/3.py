from math import sqrt
# Largest Prime Factor of 600851475143 
num = 600851475143
ans = 1
i = 3
while i<=(int(sqrt(num))+1):
    while num%i == 0:
        ans = i
        num = num//i
    i += 2
if num > 2:
    ans = num
print(ans)
