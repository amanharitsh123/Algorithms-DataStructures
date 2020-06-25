#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define MOD 1000000007

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli num,lli base) {
  lli ans = 1;
  while(base>0) {
    if(base&1)
      ans = mul(ans, num);

    num = mul(num, num);
    base >>= 1;
  }

  return ans;
}

vector<vector<int>> adj;
vector<int> final_ans;
stack<int> s;
vector<bool> visited;
map<int, int> mp;
int target;
bool dfs(int source , int size, int parent) {
  s.push(source);
  for(auto v:adj[source]) {
    if(v==parent)
      continue;
    if(mp.find(v)!=mp.end()) {
      if(size-mp[v]+1<=target) {
        while(s.size() and s.top()!=v)
          final_ans.pb(s.top()), s.pop();
        final_ans.pb(v);
        return true;
      }
      continue;
    }

    mp[source] = size;
    visited[source] = true;
    if(dfs(v, size+1, source))
      return true;
    mp[source] = 0;
  }

  s.pop();
  return false;
}

void solve() {
  int n, m, k, u, v;
  cin >> n >> m >> k;
  adj.resize(n);
  for(int i=0; i<m; i++) {
    cin >> u >> v, --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  // try to solve problem one
  vector<pi> q;
  for(int i=0; i<n; i++) {
    q.pb({adj[i].size(), i});
  }

  sort(all(q));
  vector<bool> chosen(n, false);
  vector<int> ans;
  target = k%2==0?k/2:k/2+1;
  for(auto x:q){
    if(chosen[x.second])
      continue;
    ans.pb(x.second);
    for(auto y:adj[x.second])
      chosen[y] = true;
    
    if(ans.size()==target)
      break;  
  }

  if(n==100000 and m==100000 and k==99999) {
    cout <<"size is "<<ans.size() << endl;
  }
  if(ans.size() == target) {
      cout << 1 << endl;
      for(auto x:ans)
        cout << x+1 << " ";
      cout << endl;
      return;
  }


  visited.resize(n, false);
  bool possible = false;
  target = k;
  for(int i=0; i<n and !possible; i++) {
    if(visited[i])
      continue;
    possible = possible or dfs(i, 0, -1);
  }

  cout << 2 << endl;
  cout << final_ans.size() << endl;;
  for(auto x:final_ans)
    cout << x+1 << " ";
  cout << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}
