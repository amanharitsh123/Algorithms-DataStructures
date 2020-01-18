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
    lli n,a,b,c;
    cin>>n>>a>>b>>c;
    lli ans = 3;
    if(a+b+c<=n)
      ans=1;
    else if(a+b<=n and c<=n)
      ans=2;
    else if(b+c<=n and a<=n)
      ans=2;
    cout<<ans<<endl;
	}
}

