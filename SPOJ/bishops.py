from sys import stdin

for line in stdin:
    n = int(line)
    if n==0:
        print(0)
    elif n==1:
        print(1)
    else:
        print(2*n-2)