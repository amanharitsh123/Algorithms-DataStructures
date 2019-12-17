
def mul(a,b):
    if len(b)>len(a):
        a,b = b,a
    ans = '0'
    carry = 0
    j = len(b-1)
    while j>=0:
        final = []
        n1 = b[j]
        i = len(a)-1
        while i>=0 or carry:
            n2 = a[i] if i>=0 else 0
            temp = int(n1)*int(n2) + carry
            carry = temp//10
            temp = temp%10
            final.append(str(temp))
            i -= 1




st = '0'
for i in range(1,100):
    st = mul(st,str(i))
ans = 0
for x in st:
    ans += int(st)