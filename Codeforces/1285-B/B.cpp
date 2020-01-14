#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include <numeric>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli t;
	cin>>t;
	while(t--) {
    lli n;
    cin>>n;
    vector<lli> arr(n);
    lli ma = -1000000000;
    lli ans = -1000000000;
    lli sum = 0;
    For(0,n)
      cin>>arr[I];
    sum = accumulate(arr.begin(),arr.end(),sum);
    For(0,n-1)
    {
      if(ma<0)
      {
        ma = arr[I];
      }
      else
      {
        ma += arr[I];
      }
      ans = max(ans,ma);
    }
    ma = 0;
    For(1,n)
    {
      if(ma<0)
      {
        ma = arr[I];
      }
      else
      {
        ma += arr[I];
      }
      ans = max(ans,ma);
    }
    //cout<<sum<<" --- "<<ans<<endl;
    if(sum>ans)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

	}
}

