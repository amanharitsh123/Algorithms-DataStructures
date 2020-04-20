#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
using namespace std;
typedef unsigned long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  T temp;
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}


lli power(lli num,lli base,lli mod) {
  if(base==0)
    return 1LL;

  if(base%2)
    return ((__int128)num%mod*power(num,base-1LL,mod)%mod)%mod;
  else {
    __int128 x=power(num,base/2,mod);
    x=(x*x)%mod;
    return x;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli a,b,n;
    cin>>a>>b>>n;
    lli v=max(a,b)-min(a,b);
    // x=a^n,y=b^n
    lli x,y;
    if(v!=0) {
      x=power(a,n,v),y=power(b,n,v);
      cout<<__gcd(v,(x+y)%v)%MOD<<endl;
    }
    else {
      x=power(a,n,MOD),y=power(b,n,MOD);
      cout<<(x+y)%MOD<<endl;
    }

    //cout<<__gcd(v,x+y)%MOD<<endl;
	}
}

