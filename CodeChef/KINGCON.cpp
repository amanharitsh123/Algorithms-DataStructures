#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define N 3001
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

bool articulate[N];
bool visited[N];
int parent[N];
int desc[N];
int low[N];
int dtime = 0;
vector<int> adj[N];
/*
  Algorithm to find articulate nodes in a graph
  1) Root node with more than 1 children.
  2) Non root node where low_value of this node is >= desc_time for this node.
*/

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

void dfs(int u) {
  int child = 0;
  low[u] = desc[u] = dtime;
  ++dtime;
  visited[u] = true;
  for(auto v:adj[u]) {
    if(!visited[v]) {
      child += 1;
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      // if root
      if(parent[u]==-1 and child > 1)
        articulate[u] = true;
      if(parent[u]!=-1 and low[v]>=desc[u])
        articulate[u] = true;
    }
  }
}

void solve() {
  int n, m, k, count = 0;
  cin >> n >> m >> k;
  dtime = 0;
  for(int i=0; i<n; i++)
    adj[i].clear(), visited[i] = false, parent[i] = -1, articulate[i] = false;

  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=0; i<n; i++) {
    if(!visited[i])
      dfs(i);
  }

  for(int i=0; i<n; i++) {
    if(articulate[i])
      ++count;
  }

  cout << count*k << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

