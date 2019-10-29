#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli t;
    cin>>t;
    lli mod=1000003;
    while(t--)
    {
        lli n;
        cin>>n;
        vector<lli> arr(n);
        lli * count=new lli[1000000+1]();
        lli * sum=new lli[1000000+1]();
        
        for(lli i=0;i<n;i++)
            {cin>>arr[i];count[arr[i]]++;count[arr[i]]=count[arr[i]]%mod;}
        lli ans=0;
        lli limit=*max_element(arr.begin(),arr.end());
        for(lli i=1;i<1000001;i++)
        {
            sum[i]=sum[i-1]+count[i];
        }
        // cout<<"limit is "<<limit<<endl;
        for(lli i=0;i<n;i++)
        {
            lli l=arr[i];
            lli r=2*arr[i]-1;
            lli mul=3;
            while(l<=limit)
            {
                // lli count=upper_bound(arr.begin(),arr.end(),r)-lower_bound(arr.begin(),arr.end(),l);
                r=min(r,1000000);
                lli c=sum[r]-sum[l];
                if(count[l])
                    ++c;
                c=c%mod;
                    
                // cout<<l<<" "<<r<<" "<<c<<endl;
                ans=(ans%mod+(c*(mul-2)%mod))%mod;
                l=((mul-1)%mod*arr[i]%mod)%mod;
                r=((mul)%mod*arr[i]-1)%mod;
                ++mul;
                mul=mul%mod;

            }
        }
        cout<<ans<<endl;
    
        delete count;
        delete sum;
    }
    return 0;
}