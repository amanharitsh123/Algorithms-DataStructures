#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod = 1000000007;

// Solution reduces to this formulae
// x/y = (m**(n-1)+m**(n-2)....+m**(0)) / m**n
// x = (y-1) / (m-1)
// y = m**n

lli mexp(lli m, lli n) {
    
    if(n==0)
        return 1;
    if(n%2)
    {
        return (mexp(m,n-1)%mod*m%mod)%mod;
    
    } else
    {
        lli t = mexp(m,n/2)%mod;
        return (t*t)%mod;   
    }
}

lli inv(lli n,lli m,lli *x, lli *y)
{
    if(n==0)
    {
        *x = 0;
        *y = 1;
        return m;
    }
    lli x1,y1;
    lli g = inv(m%n,n,&x1,&y1);
    *y = x1;
    *x = y1 - (m/n)*x1;
    return g;
}

lli solve(lli m)
{
    lli x,y;
    inv(m,mod,&x,&y);
    return x;
}

int main() {
    lli tc;
    cin>>tc;
    while(tc--) {
        lli n,m,x,y,inv;
        cin>>m>>n;
        y = mexp(m,n)%mod;
        inv = solve(m-1)%mod;
        x = ((y-1)*inv)%mod;
        cout<<(mod+x%mod)%mod<<" "<<y<<endl;
    }
}

