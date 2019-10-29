# gcd(a,b)*lcm(a,b) = a*b
# Naive Solution: O(mint(a,b))
# Efficient Solution: O(log) using Euclidean Algorithm O(log(ab))
def gcd(a,b):
    if a%b==0:
        return b
    return gcd(b,a%b)
print(gcd(20,19))
