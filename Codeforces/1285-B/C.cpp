#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<cmath>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)

lli lcm(lli a,lli b)
{
  return (a*b) / (__gcd(a,b));
}
int main() {
	lli x;
	cin>>x;
  lli mi = 1;
	for(lli n=sqrtl(x);n>=1;n--)
  {
    if(x%n==0 and (lcm(n,x/n)==x))
    {
      mi = max(n,x/n);
      break;
    } 
  }
  cout<<min(mi,x/mi)<<" "<<max(mi,x/mi)<<endl;
}

