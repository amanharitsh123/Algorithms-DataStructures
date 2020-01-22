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
  lli x=0 ,y=0 ,z=0;
	while(t--) {
	  lli a,b,c;
    cin>>a>>b>>c;
    x+=a;
    y+=b;
    z+=c;
  }
  if(x==0 and y==0 and z==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}

