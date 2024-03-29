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
    lli n,m,c,l;
    cin>>n>>m;
    map<lli,lli> mp;
    for(lli i=0;i<n;i++) {
      cin>>c>>l;
      if(mp.find(l)!=mp.end())
        mp[l]+=c;
      else
        mp[l]=c;
    }

    lli ans=0;
    for(lli i=0;i<m;i++) {
      cin>>c>>l;
      mp[l]-=c;
    }

    for(auto x:mp) {
      ans+=min(0LL,(x).second);
    }
    cout<<abs(ans)<<endl;
	}
}

