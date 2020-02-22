#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
    lli testcases,n,m,price;
    lli ans;
    string line;
    char x;
    cin>>testcases;
    while(testcases--) {
        ans=0;
        unordered_map<char,lli> mp;
        cin>>n;
        for(lli i=0;i<n;i++)
        {
            cin>>x>>price;
            mp[x]=price;
        }
        cin>>m;
        getline(cin,line);
        for(lli i=0;i<m;i++)
        {
            getline(cin,line);
            // cout<<i<<" "<<line;
            for(auto x:line)
            {
                if(mp.find(x)!=mp.end())
                    ans+=mp[x];
                // cout<<x;
            }
            // cout<<endl;      
        }
        printf("%lld.%02lld$\n", ans/100, ans%100);
    }
}

/*
Sample Input
1
7
a 3
W 10
A 100
, 10
k 7
. 3
I 13
7
ACM International Collegiate Programming Contest (abbreviated
as ACM-ICPC or just ICPC) is an annual multi-tiered competition
among the universities of the world. The ICPC challenges students
to set ever higher standards of excellence for themselves
through competition that rewards team work, problem analysis,
and rapid software development.
From Wikipedia.
Sample Output
3.74$
*/