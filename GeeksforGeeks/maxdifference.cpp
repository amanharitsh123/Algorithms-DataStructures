#include<iostream>
#include<bits/stdc++.h>
#include<utility>
typedef long long int lli;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lli *arr=new lli[n];
        for(lli i=0;i<n;i++)
            cin>>arr[i];
        lli mi=0;
        vector< pair<lli,lli> > rmax;
        int i=0,j=0;
        
        for(int i=n-1;i>=0;i--)
        {
            mi=max(mi,arr[i]);
            rmax.push_back(make_pair(mi,i));
        }
         i=0;
         j=n-1;
        mi=LONG_MAX;
        lli ans=0;
        while(i<n and j>=0)
        {
            mi=min(mi,arr[i]);
            if(mi<=rmax[j].first)
            {
                ans=max(ans,rmax[j].second-i);
                j-=1;
            }else
            {
                i+=1;
            }
            

        }
        cout<<ans<<endl;
    }
    
}

// # 1
// # 9
// # 34 8 10 3 2 80 30 33 1