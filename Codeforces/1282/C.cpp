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
	lli t;
	cin>>t;
	while(t--) {
    lli n,t,a,b;
    cin>>n>>t>>a>>b;
    vector<lli> arr(n);
    vector<lli> diff(n);
    
    For(0,n)
      cin>>diff[I];
    
    For(0,n)
      cin>>arr[I];
    
    vector< pair<lli,lli> > data;
    
    For(0,n)
      data.push_back({arr[I],diff[I]});

    sort(data.begin(),data.end());
    lli ans = 0;
    lli prev = 0;
    lli time = 0;
    For(0,n)
    {
      lli cnt = 0;
      bool first = true;
      while(I<n and (data[I].first<=time or first))
      {
        first = false;
        ++cnt;
        lli type = data[I].second;
        if(type)
          time += b;
        else
          time += a;
        ++I;
      }
      // cout<<"time is "<<time<<" "<<t<<endl;
      if(time<=t)
      {
        ans += cnt;
      }
      --I;
    }
    cout<<ans<<endl;
	}
}
