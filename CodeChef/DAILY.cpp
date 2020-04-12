#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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

lli ncr(lli n,lli r) {
  if(r>n)
    return 0;
  if(r==n || r==0)
    return 1;
  return ncr(n-1,r-1) + ncr(n-1,r);
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases,x;
	cin>>x>>testcases;
  lli ans=0;
	while(testcases--) {
    string inp;
    cin>>inp;
    lli top=53;
    lli free=0;
    for(lli i=0;i<36;i+=4) {
      free=0;
      for(lli j=i;j<i+4;j++) {
        if(inp[j]=='0')
          ++free;
      }
      if(inp[top]=='0')
        ++free;
      --top;
      if(inp[top]=='0')
        ++free;
      --top;
      ans+=ncr(free,x);
    }
	}
  cout<<ans<<endl;
}

