#include<iostream>
using namespace std;
typedef long long int lli;
# define for(i,n) for(lli test_case=i;test_case<n;test_case++)
int main() {
    lli t;
    cin>>t;
    for(0,t) {
        lli a,b,c,r;
        cin>>a>>b>>c>>r;
        if(b<a)
        {
            b = b^a;
            a = b^a;
            b = b^a;
        }
        lli left = c-r;
        lli right = c+r;
        lli time = b-a;
        if(right<a or left>b)
            cout<<time<<endl;
        else
        {
            left = max(a,left);
            right = min(right,b);
            cout<<left-a+b-right<<endl;
        }
        
    }    
}