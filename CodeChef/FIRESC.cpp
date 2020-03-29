#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<queue>
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

lli bfs(vector<lli> &visited, vector< vector<lli> > &adj,lli source) {
  queue<lli> q;
  q.push(source);
  lli count=0;
  while(q.size()) {
    lli top=q.front();
    q.pop();
    if(visited[top])
      continue;
    ++count;
    visited[top]=1;
    for(auto v:adj[top]) {
      if(!visited[v])
        q.push(v);
    }
  }
  return count;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
  lli mod=1000000000 + 7;
	while(testcases--) {
    // Counting number of disjoint graphs by bfs
    lli n,m;
    cin>>n>>m;
    vector< vector<lli> > adj(n);
    for(lli i=0;i<m;i++) {
      lli u,v;
      cin>>u>>v, --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    lli distinct=0;
    lli ways=1;
    vector<lli> visited(n,0);

    for(lli u=0;u<n;u++) {
      if(!visited[u]) {
        ++distinct;
        ways=(ways*bfs(visited,adj,u))%mod;
        ways=ways%mod;
      }
    }
    cout<<distinct<<" "<<ways%mod<<endl;
	}
}

