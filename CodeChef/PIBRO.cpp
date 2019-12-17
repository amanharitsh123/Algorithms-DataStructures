#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli t;
    cin>>t;
    while(t--) {
        lli n,k;
        cin>>n>>k;
        string inp;
        cin>>inp;
        vector<lli> right(n+1);
        lli count = 0;
        for(lli i=n-1;i>=0;i--) {
            if(inp[i]=='1')
                ++count;
            else
                count = 0;
            right[i]=count;
        }
        count = 0;
        lli ans = 0;
        for(lli i=0;i<n-k+1;i++)
        {
            lli length = count + k + right[i+k];
            ans = max(ans,length);
            if(inp[i]=='1')
                ++count;
            else
                count = 0; 
        }
        cout<<ans<<endl;
    }
}