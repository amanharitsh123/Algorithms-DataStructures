#include <iostream>
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main()
{
    double n,m,a;
    cin>>n>>m>>a;
    lli v1 = ceil(n/a);
    cout<<n/a<<endl;
    lli v2 = ceil(m/a);
    lli ans = v1*v2;
    cout<<v1*v2<<endl;

}