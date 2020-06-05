#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli t;
    cin>>t;
    while(t--) {
        lli n;
        cin>>n;
        vector<lli> arr(n);
        for(lli i=0;i<n;i++)
            cin>>arr[i];
        lli k;
        cin>>k;
        k = arr[k-1];
        lli ans = 0;
        for(auto x:arr)
        {
            if(x<k)
                ++ans;
        }
        cout<<ans+1<<endl;

    }
}
// 3
// 4
// 1 3 4 2
// 2
// 5
// 1 2 3 9 4
// 5
// 5
// 1 2 3 9 4 
// 1
