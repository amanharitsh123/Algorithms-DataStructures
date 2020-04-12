#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<stdlib.h>
#define all(arr) arr.begin(),arr.end()
using namespace std;
typedef long long int lli;

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
  
lli mod=1000000007;

lli fast(lli h) {
  lli ans=1;
  if(h==0)
    return 1;

  if(h%2) {
    ans=(2*fast(h-1))%mod;
    ans=ans%mod;
  } else {
    lli x=fast(h/2);
    ans=(x*x)%mod;
  }
  return ans%mod;
}


lli solve(lli n) {
    lli h=n/2;
    if(n%2==0) {
      lli ans=(3*(fast(h)%mod)%mod - 2)%mod;
      return ans%mod;
    } else {
      return (2*(fast(h+1)%mod-1%mod))%mod;
    }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    cout<<solve(n)<<endl;
	}
}

