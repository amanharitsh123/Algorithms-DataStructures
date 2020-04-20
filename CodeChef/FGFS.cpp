#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<climits>
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

struct event {
  lli s,f;

  bool operator<(const event& o) const {
    if(f!=o.f)
      return f<o.f;
    else
      return s>o.s;
  }
};

lli solve(vector<event> &arr) {
  lli n=arr.size();
  lli prev=0;
  lli  ans=0;
  for(auto x:arr) {
    if(x.s >= prev)
      ++ans,prev=x.f;
  }

  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,k,s,f,p;
    cin>>n>>k;
    map<lli,vector<event> > mp;
    lli ans=0;
    for(lli i=0;i<n;i++) {
      cin>>s>>f>>p;
      event x={s,f};
      if(mp.find(p)!=mp.end())
        mp[p].push_back(x);
      else
        mp[p]={x};
    }

    for(auto x:mp) {
      sort(all(x.second));
      ans+=solve(x.second);
    }

    cout<<ans<<endl;
	}
}

