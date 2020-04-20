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

vector<lli> values;
vector< vector<lli> > adj;
lli x=-1;

lli dfs(lli root,lli parent) {
  lli ans=0;
  for(auto v:adj[root]) {
    if(v==parent)
      continue;
    ans+=dfs(v,root);
  }
  return max(ans+values[root],-1*x);
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    lli n,X;
    values.clear();
    cin>>n>>X;
    x=X;
    input(values,n);
    adj.clear();
    adj.resize(n);
    for(lli i=0;i<n-1;i++) {
      lli u,v;
      cin>>u>>v,--u,--v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout<<dfs(0,-1)<<endl;
	}
}

