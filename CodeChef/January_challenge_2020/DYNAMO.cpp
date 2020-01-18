#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef unsigned long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#define FLUSH fflush(stdout)

lli pow(lli x,lli n) {
  lli ans=1;  
  while(n)
    {
      ans=ans*x;
      n--;
    }
  return ans;
}

int main() {
	lli t;
	cin>>t;
	while(t--) {
    // N-> 
    // A->
    // <-s
    // B->
    // <-C
    // D->
    // <-E
    // s = 2*(10^N-1) + 2 + A
    lli n,s,a,b,c,d,e,verdict;
    cin>>n;
    cin>>a;
    cout<<2*(pow(10,n)-1) + 2 + a<<endl;
    FLUSH;
    cin>>b;
    cout<<pow(10,n)-b<<endl;
    FLUSH;
    cin>>d;
    cout<<pow(10,n)-d<<endl;
    FLUSH;
    cin>>verdict;
    if(verdict==-1)
      break;
	}
}

