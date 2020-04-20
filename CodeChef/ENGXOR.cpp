#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  arr.resize(n);
  for(lli i=0;i<n;i++) scanf("%lld",&arr[i]);
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


lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

bool even(lli x) {
  lli count=0;
  for(lli i=0;i<30;i++) {
    if(x&(1LL<<i))
      ++count;
  }
  return count%2==0;
}

int main() {
  
  lli testcases;
	scanf("%lld",&testcases);
	while(testcases--) {
    lli n,q;
    cin>>n>>q;
    vector<lli> arr;
    input(arr,n);
    lli e=0,o=0;
    for(auto x:arr)
      if(even(x))
        ++e;
      else
        ++o;

    while(q--) {
      lli p;
      scanf("%lld",&p);
      if(even(p))
        cout<<e<<" "<<o<<endl;
      else
        cout<<o<<" "<<e<<endl;
    }
	}
}

