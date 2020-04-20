#include<iostream>
#include<vector>
#include<set>
#include<limits.h>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define MOD 1000000007
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

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n;
    cin>>n;
    vector<lli> arr;
    input(arr,n);
    map<lli,lli> mp;
    lli mi=LLONG_MAX;
    for(auto x:arr) {
      mi=min(mi,x);
      if(mp.find(x)==mp.end())
        mp[x]=1;
      else
        mp[x]++;
    }

    lli ans=true;
    for(auto x:arr) {
      if(x==mi)
        continue;
      if(mp.find(x-1)==mp.end() or mp[x-1]==0) {
        ans=false;
        break;
      }
      --mp[x-1];
    }

    if(ans)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
	}
}

