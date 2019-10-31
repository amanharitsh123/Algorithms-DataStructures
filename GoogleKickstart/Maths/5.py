from math import gcd
num = 1
for i in range(1,21):
    num = (num*i)//(gcd(num,i))
print(num)