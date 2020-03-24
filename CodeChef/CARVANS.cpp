#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<limits.h>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli t,i,n,mi,count;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	cin>>t;
  lli arr[10000];
	while(t--) {
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    mi=LLONG_MAX;
    count=0;
    for(i=0;i<n;++i) {
      if(arr[i]<=mi)
        ++count;
      mi=min(arr[i],mi);
    }
    cout<<count<<"\n";
	}
}

